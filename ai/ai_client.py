import re
from queue import Queue
from typing import List, Tuple

from client import Client

SERVER_BANNER = 'WELCOME'
DEFAULT_INVENTORY = {
    'food': 7,
    'linemate': 0,
    'deraumere': 0,
    'sibur': 0,
    'mendiane': 0,
    'phiras': 0,
    'thystame': 0
}
INCANTATION_REQUIREMENTS = [
    {'players': 1, 'linemate': 1, 'deraumere': 0, 'sibur': 0, 'mendiane': 0, 'phiras': 0, 'thystame': 0},
    {'players': 2, 'linemate': 1, 'deraumere': 1, 'sibur': 1, 'mendiane': 0, 'phiras': 0, 'thystame': 0},
    {'players': 2, 'linemate': 2, 'deraumere': 0, 'sibur': 1, 'mendiane': 0, 'phiras': 2, 'thystame': 0},
    {'players': 4, 'linemate': 1, 'deraumere': 1, 'sibur': 2, 'mendiane': 0, 'phiras': 1, 'thystame': 0},
    {'players': 4, 'linemate': 1, 'deraumere': 2, 'sibur': 1, 'mendiane': 3, 'phiras': 0, 'thystame': 0},
    {'players': 6, 'linemate': 1, 'deraumere': 2, 'sibur': 3, 'mendiane': 0, 'phiras': 1, 'thystame': 0},
    {'players': 6, 'linemate': 2, 'deraumere': 2, 'sibur': 2, 'mendiane': 2, 'phiras': 2, 'thystame': 1}
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
    'inventory': AICommand('Inventory', [r'\[ \w+ [1-9]\d*(, \w+ [1-9]\d*)* \]']),
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

    def start_handshake(self):
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

    def execute_command(self, command: AICommand, arguments: List[str] = []) -> List[str]:
        self.send_line(f'{command.call_id}{" " if len(arguments) else ""}{" ".join(arguments)}')

        response = self.receive_lines_until_matches_regex(
            list(map(lambda response_format: fr'^({response_format}|dead)$', command.response_format))
        )

        if "dead" in response:
            exit(0)
        for eject_message in filter(lambda msg: msg.startswith("eject"), response):
            self.received_ejects.put(eject_message)
        for broadcast_message in filter(lambda msg: msg.startswith("message"), response):
            self.broadcast_messages.put(broadcast_message)
        response = list(filter(lambda msg: not msg.startswith("eject") and not msg.startswith("message"), response))

        for index, response_line in enumerate(response):
            if not re.match(command.response_format[index], response_line):
                raise RuntimeError(
                    f'Invalid server response: to command {command.call_id}, got invalid line \'{response_line}\'')
        return response
