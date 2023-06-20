from ai_client import AIClient, COMMANDS
from typing import List, Tuple


def travel(client: AIClient, posx: int, posy: int) -> None:
    while True:
        if posx == 0 and posy == 0:
            break
        if posy > 0:
            client.execute_command(COMMANDS['Forward'])
            posy -= 1
        if posy < 0:
            client.execute_command(COMMANDS['Right'])
            posx, posy = posy, -posx
            client.execute_command(COMMANDS['Right'])
            posx, posy = posy, -posx
        if posy == 0:
            if posx < 0:
                client.execute_command(COMMANDS['Right'])
                posx, posy = -posy, posx
            if posx > 0:
                client.execute_command(COMMANDS['Left'])
                posx, posy = -posy, posx
