from client import Client
import re

SERVER_BANNER = 'WELCOME'

class AIClient(Client):
    def __init__(self, server: tuple[str, int], team_name: str) -> None:
        super().__init__(server)
        self.team_name = team_name
        self.team_available_slots = 0
        self.position = None

    def start_handshake(self):
        if SERVER_BANNER not in self.receive_lines():
            raise RuntimeError('Can\'t find server banner.')
        
        self.send_line(self.team_name)
        res = self.receive_lines()

        if len(res) != 2 or not re.match(r'\d+', res[0]):
            raise RuntimeError('Invalid server\'s response: bad handshake response format.')
        
        position_match = re.match(r'([1-9]\d*) ([1-9]\d*)', res[1])

        if not position_match:
            raise RuntimeError('Invalid server\'s response: bad position format.')
        
        try:
            self.team_available_slots = int(res[0])
            self.position = (int(position_match[1]), int(position_match[2]))
        except ValueError:
            raise RuntimeError('Invalid server response: non decimal numbers.')