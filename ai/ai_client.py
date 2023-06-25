import base64
import os
import logging
import re
import sys
from queue import Queue
from typing import List, Tuple, Dict
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import padding, rsa


from client import Client

SERVER_BANNER = 'WELCOME'
DEFAULT_INVENTORY = {
    'food': 10,
    'linemate': 0,
    'deraumere': 0,
    'sibur': 0,
    'mendiane': 0,
    'phiras': 0,
    'thystame': 0
}

ROCKS_PRIORITY = [
    'phiras',
    'mendiane',
    'sibur',
    'deraumere',
    'linemate',
]

BROADCAST_MESSAGES = {
    'incant': 'ready to incant, need players',
    'resources': 'i need resources',
    'enemy': 'enemy spotted',
    'level': 'i\'m level',
    'dead': 'i\'m dead :(',
    'team': 'are you with me ?',
    'position': 'i\'m here',
    'affirmative': 'yes',
    'cartman': 'fuck you i\'m going home'
}

RELATIVE_POSITIONS_LOOK_MAPPINGS = [
    (0, 0),
    (-1, 1),
    (0, 1),
    (1, 1),
    (-2, 2),
    (-1, 2),
    (0, 2),
    (1, 2),
    (2, 2),
    (-3, 3),
    (-2, 3),
    (-1, 3),
    (0, 3),
    (1, 3),
    (2, 3),
    (3, 3),
]

INCANTATION_REQUIREMENTS = [
    {'player': 1, 'linemate': 1, 'deraumere': 0, 'sibur': 0, 'mendiane': 0, 'phiras': 0, 'thystame': 0},
    {'player': 2, 'linemate': 1, 'deraumere': 1, 'sibur': 1, 'mendiane': 0, 'phiras': 0, 'thystame': 0},
    {'player': 2, 'linemate': 2, 'deraumere': 0, 'sibur': 1, 'mendiane': 0, 'phiras': 2, 'thystame': 0},
    {'player': 4, 'linemate': 1, 'deraumere': 1, 'sibur': 2, 'mendiane': 0, 'phiras': 1, 'thystame': 0},
    {'player': 4, 'linemate': 1, 'deraumere': 2, 'sibur': 1, 'mendiane': 3, 'phiras': 0, 'thystame': 0},
    {'player': 6, 'linemate': 1, 'deraumere': 2, 'sibur': 3, 'mendiane': 0, 'phiras': 1, 'thystame': 0},
    {'player': 6, 'linemate': 2, 'deraumere': 2, 'sibur': 2, 'mendiane': 2, 'phiras': 2, 'thystame': 1}
]


class AICommand:
    def __init__(self, call_id: str, response_format: List[re.Pattern]) -> None:
        self.call_id = call_id
        self.response_format = response_format


COMMANDS = {
    'forward': AICommand('Forward', [r'ok']),
    'right': AICommand('Right', [r'ok']),
    'left': AICommand('Left', [r'ok']),

    'look': AICommand('Look', [r'\[ .+(, .+)* \]']),
    'inventory': AICommand('Inventory', [r'\[ \w+ \d+(, \w+ \d+)* \]']),
    'broadcast': AICommand('Broadcast', [r'ok']),

    'connect_nbr': AICommand('Connect_nbr', [r'[1-9]\d*']),
    'fork': AICommand('Fork', [r'ok']),
    'eject': AICommand('Eject', [r'(ok|ko)']),

    'take': AICommand('Take', [r'(ok|ko)']),
    'set': AICommand('Set', [r'(ok|ko)']),
    'incantation': AICommand('Incantation', [r'(Elevation underway|ko)', r'(Current level: [1-8]|ko)'])
}


class AIClient(Client):
    def __init__(self, server: Tuple[str, int], team_name: str, time_unit: int = 100) -> None:
        super().__init__(server)
        self.team_name = team_name
        self.team_available_slots = 0
        self.position = None
        self.time_unit = time_unit
        self.broadcast_messages = Queue()
        self.received_ejects = Queue()
        self.inventory = DEFAULT_INVENTORY
        self.elevation = 1
        self.private_key = None
        self.public_key = None
        self.direct_child = 0

    def start_handshake(self) -> None:
        if SERVER_BANNER not in self.receive_lines():
            raise RuntimeError('Can\'t find server banner.')

        self.send_line(self.team_name)
        response = self.receive_lines()

        if len(response) != 2 or not re.match(r'\d+', response[0]):
            raise RuntimeError('Invalid server response: bad handshake response format.')

        position_match = re.match(r'([1-9]\d*) ([1-9]\d*)', response[1])

        if not position_match:
            raise RuntimeError('Invalid server response: bad position format.')

        try:
            self.team_available_slots = int(response[0])
            self.position = (int(position_match[1]), int(position_match[2]))
        except ValueError:
            raise RuntimeError('Invalid server response: non decimal numbers.')

    def execute_command(self, command: AICommand, arguments: List[str] = ()) -> List[str]:
        logging.debug(f'Executing command {command.call_id} with arguments {arguments if len(arguments) else "none"}')
        self.send_line(f'{command.call_id}{" " if len(arguments) else ""}{" ".join(arguments)}')

        response = self.receive_lines_until_matches_regex(
            list(map(lambda response_format: re.compile(fr'^({response_format}|dead)$'), command.response_format))
        )

        if "dead" in response:
            logging.fatal('deadge')
            exit(0)
        filtered_response = []
        for line in response:
            if line.startswith("eject"):
                self.received_ejects.put(line)
            elif line.startswith("message"):
                self.broadcast_messages.put(line)
            else:
                filtered_response.append(line)
        logging.debug(f'Last command response: {filtered_response}')
        return filtered_response

    def refresh_inventory(self) -> None:
        logging.info("Refreshing inventory...")
        raw_inventory = self.execute_command(COMMANDS['inventory'])[0]

        items = re.findall(r'\w+ \d+', raw_inventory)

        for item in items:
            item_name, item_quantity = item.split()
            self.inventory[item_name] = int(item_quantity)

    def drop_item(self, item: str) -> None:
        logging.info(f"Dropping {item}")
        if self.inventory.get(item, 0) < 0:
            raise ValueError('Cannot drop an item that is not in the inventory.')
        if 'ko' in self.execute_command(COMMANDS['set'], [item]):
            raise RuntimeError('Could not drop item.')
        self.inventory[item] -= 1

    def encrypt_message(self, message: str) -> str:
        public_key = serialization.load_pem_public_key(self.public_key)

        ciphertext = public_key.encrypt(
            message.encode('utf-8'),
            padding.OAEP(
                mgf=padding.MGF1(algorithm=hashes.SHA256()),
                algorithm=hashes.SHA256(),
                label=None
            )
        )
        return base64.b64encode(ciphertext).decode('utf-8')

    def decrypt_message(self, message: str) -> str:
        private_key = serialization.load_pem_private_key(self.private_key, password=None)

        plaintext = private_key.decrypt(
            base64.b64decode(message),
            padding.OAEP(
                mgf=padding.MGF1(algorithm=hashes.SHA256()),
                algorithm=hashes.SHA256(),
                label=None
            )
        )
        return plaintext.decode('utf-8')

    def broadcast(self, message: str) -> None:
        logging.info(f"Broadcasting {message}")
        if 'ko' in self.execute_command(COMMANDS['broadcast'], [self.encrypt_message(message)]):
            raise RuntimeError('Could not broadcast message.')

    def ask_for_incanation(self, nb_players: int) -> None:
        logging.info(f"Requesting incantation with {nb_players} players at level {self.elevation}")
        self.broadcast(BROADCAST_MESSAGES['incantation'] + f' {nb_players} , {self.elevation}')

    def ask_for_team(self) -> None:
        logging.info(f"Requesting team")
        self.broadcast(BROADCAST_MESSAGES['team'])

    def ask_for_resources(self, resources: str) -> None:
        logging.info(f"Requesting resources {resources}")
        self.broadcast(BROADCAST_MESSAGES['resources'] + f' {resources}')

    def check_received_messages(self) -> None:
        check = False
        while not self.broadcast_messages.empty():
            message = self.broadcast_messages.get()
            # check if message looks like message from BROADCAST_MESSAGES
            for broadcast_message in BROADCAST_MESSAGES.values():
                if message.startswith(broadcast_message):
                    check = True
                    break
        if not check:
            self.execute_command(COMMANDS['broadcast'], ["quoicoubeh ki a demandé?" + "lol".encode("utf-8").hex()])


    def take_item(self, item: str) -> None:
        logging.info(f"Taking {item}")
        if 'ko' in self.execute_command(COMMANDS['take'], [item]):
            raise RuntimeError('Could not take item.')
        self.inventory[item] += 1

    def look(self) -> List[Dict[str, int]]:
        surrounding_cells: List[Dict[str, int]] = []
        raw_look = self.execute_command(COMMANDS['look'])[0]

        for i, cell in enumerate(raw_look.split(',')):
            surrounding_cells.append({})
            for item in re.findall(r'\w+', cell):
                surrounding_cells[i][item] = surrounding_cells[i].get(item, 0) + 1
        return surrounding_cells

    def can_incantate(self) -> bool:
        current_cell = self.look()[0]
        for requirement, amount in INCANTATION_REQUIREMENTS[self.elevation - 1].items():
            if current_cell.get(requirement, 0) < amount:
                return False
        return True

    def drop_incatation_needs(self) -> None:
        logging.info(f'Dropping incantation needs for elevation {self.elevation}')
        for need, amount in INCANTATION_REQUIREMENTS[self.elevation - 1].items():
            if need == 'player':
                continue
            for _ in range(amount):
                self.drop_item(need)

    def incantate(self) -> None:
        logging.warning(f'Starting incantation for elevation {self.elevation}')
        if not self.can_incantate() or 'ko' in self.execute_command(COMMANDS['incantation']):
            raise RuntimeError('Could not incantate.')
        self.elevation += 1
        logging.warning(f'End of incantation, now at elevation {self.elevation}')

    def get_priority_ordered_incantation_needs(self) -> List[Tuple[str, int]]:
        return list(filter(
            lambda need: need[1] < 0,
            map(
                lambda rock_name: (
                    rock_name,
                    self.inventory.get(rock_name, 0) - INCANTATION_REQUIREMENTS[self.elevation - 1][rock_name]
                ),
                ROCKS_PRIORITY.copy()
            )
        ))

    def reproduce(self) -> None:
        if 'ko' in self.execute_command(COMMANDS['fork']):
            raise RuntimeError('Could not reproduce.')
        self.direct_child += 1
        try:
            pid = os.fork()
            if pid == 0:
                os.execv(os.getcwd() + '/zappy_ai', sys.argv)
            else:
                logging.info(f'Child {pid} created.')
        except OSError:
            raise RuntimeError('Could not fork.')


    def get_target_cell_for_item(self, item: str) -> Tuple[int, int] or None:
        surroundings = list(
            map(lambda cell: (RELATIVE_POSITIONS_LOOK_MAPPINGS[cell[0]], cell[1]), enumerate(self.look()))
        )
        surroundings.sort(key=lambda cell: abs(cell[0][0]) + (1 if cell[0][0] != 0 else 0) + abs(cell[0][1]))
        for relative_position, cell_content in surroundings:
            if item in cell_content:
                return relative_position
        return None

    def go_to(self, x: int, y: int) -> None:
        logging.info(f'Going to {x}, {y}')
        while x != 0 or y != 0:
            if y > 0:
                self.execute_command(COMMANDS['forward'])
                y -= 1
                continue
            if y < 0:
                self.execute_command(COMMANDS['right'])
                self.execute_command(COMMANDS['right'])
                x, y = -x, -y
                continue
            if y == 0:
                if x > 0:
                    self.execute_command(COMMANDS['right'])
                    x, y = -y, x
                    continue
                else:
                    self.execute_command(COMMANDS['left'])
                    x, y = y, -x
                    continue
        logging.info('Arrived at destination.')

    def live_until_dead(self) -> None:
        while True:
            self.refresh_inventory()
            item_to_take = self.get_priority_ordered_incantation_needs()[0][0]
            target = self.get_target_cell_for_item(item_to_take)
            if target is None or self.inventory['food'] < 3:
                item_to_take = 'food'
                target = self.get_target_cell_for_item(item_to_take)
            if target is None:
                logging.info('No food found, moving forward.')
                self.execute_command(COMMANDS['forward'])
                continue
            logging.info(f'Targeting {item_to_take} at {target}.')
            self.go_to(*target)
            try:
                self.take_item(item_to_take)
            except RuntimeError:
                logging.error(
                    f'Something happened, taking {item_to_take} failed, maybe stolen or Reza\'s fault idk. '
                    f'Moving forward !'
                )
                continue
            if len(self.get_priority_ordered_incantation_needs()) == 0:
                self.drop_incatation_needs()
                try:
                    self.incantate()
                except RuntimeError:
                    logging.error(
                        'Something happened, incantation failed, maybe ejected or Reza\'s fault idk. '
                        'Let\'s pretend nothing happened...'
                    )
                    continue
