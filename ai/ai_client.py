from client import Client
import re

SERVER_BANNER = 'WELCOME'

class AICommand:
    def __init__(self, call_id: str, response_format: list[re.Pattern], time_limit: int or None) -> None:
        self.call_id = call_id
        self.response_format = response_format
        self.time_limit = time_limit

COMMANDS = {
    'forward': AICommand('Forward', [r'ok'], 7),
    'right': AICommand('Right', [r'ok'], 7),
    'left': AICommand('Left', [r'ok'], 7),

    'look': AICommand('Look', [r'\[ .+(, .+)* \]'], 7),
    'inventory': AICommand('Inventory', [r'\[ \w+ [1-9]\d*(, \w+ [1-9]\d*)* \]'], 1),
    'broadcast': AICommand('Broadcast', [r'ok'], 7),

    'connect_nbr': AICommand('Connect_nbr', [r'[1-9]\d*'], None),
    'fork': AICommand('Fork', [r'ok'], 42),
    'eject': AICommand('Eject', [r'(ok|ko)'], 7),

    'take': AICommand('Take', [r'(ok|ko)'], 7),
    'set': AICommand('Set', [r'(ok|ko)'], 7),
    'incantation': AICommand('Incantation', [r'(Elevation underway|ko)', r'Current level: [1-8]'], 300)
}

class AIClient(Client):
    def __init__(self, server: tuple[str, int], team_name: str, time_unit: int = 100) -> None:
        super().__init__(server)
        self.team_name = team_name
        self.team_available_slots = 0
        self.position = None
        self.time_unit = time_unit

    def start_handshake(self):
        if SERVER_BANNER not in self.receive_lines(None):
            raise RuntimeError('Can\'t find server banner.')
        
        self.send_line(self.team_name)
        response = self.receive_lines(None)

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
    
    def execute_command(self, command: AICommand, arguments: list[str] = []) -> list[str]:
        self.send_line(f'{command.call_id}{" " if len(arguments) else ""}{" ".join(arguments)}')

        response = self.receive_lines(None)

        actual_lines, expected_lines = len(response), len(command.response_format)

        if len(response) != len(command.response_format):
            raise RuntimeError(f'Invalid server response: to command {command.call_id}, got {actual_lines} lines but expected {expected_lines} lines')
        
        for index, response_line in enumerate(response):
            if not re.match(command.response_format[index], response_line):
                raise RuntimeError(f'Invalid server response: to command {command.call_id}, got invalid line \'{response_line}\'')
        
        return response



