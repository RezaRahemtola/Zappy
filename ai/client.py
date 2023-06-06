import socket
import os
import time

class Client:
    def __init__(self, server: tuple[str, int], timeout: float = 5) -> None:
        self.server = server
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connected = False
        self.last_send_time = 0
        self.socket.settimeout(timeout)

    def connect(self) -> bool:
        if self.connected:
            raise RuntimeError('Can\'t connect an already connected client.')
        self.connected = True
        try:
            self.socket.connect(self.server)
        except:
            return False
        return True
    
    def disconnect(self) -> bool:
        if not self.connected:
            raise RuntimeError('Can\'t disconnected a not already connected client.')
        self.connected = False
        try:
            self.socket.close()
        except:
            return False
        return True

    def send_line(self, line: str) -> None:
        line += '\n'
        line_len = len(line)
        sent = 0
        while sent < line_len:
            current_sent = self.socket.send(line[sent:].encode('utf8'))
            if current_sent == 0:
                raise RuntimeError('Couldn\'t send data.')
            sent += current_sent
        self.last_send_time = time.time()

    def receive_lines(self, read_size: int = 2048) -> list[str]:
        return self.socket.recv(read_size, os.O_NONBLOCK).decode('utf8').strip().split('\n')