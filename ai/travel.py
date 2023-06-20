from ai_client import AIClient, COMMANDS
from typing import List, Tuple


def move_forward(coordinates: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
    updated_coordinates = []
    for x, y in coordinates:
        updated_coordinates.append((x, y - 1))
    return updated_coordinates


def rotate_right(coordinates: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
    updated_coordinates = []
    for x, y in coordinates:
        updated_coordinates.append((y, -x))
    return updated_coordinates


def rotate_left(coordinates: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
    updated_coordinates = []
    for x, y in coordinates:
        updated_coordinates.append((-y, x))
    return updated_coordinates


def travel(client: AIClient, coordinates: List[Tuple[int, int]]) -> None:
    while coordinates:
        x, y = coordinates[0]
        if x == 0 and y == 0:
            coordinates.pop(0)
            continue
        if y > 0:
            client.execute_command(COMMANDS['Forward'])
            coordinates = move_forward(coordinates)
        if y < 0:
            client.execute_command(COMMANDS['Right'])
            coordinates = rotate_right(coordinates)
            client.execute_command(COMMANDS['Right'])
            coordinates = rotate_right(coordinates)
        if y == 0:
            if x < 0:
                client.execute_command(COMMANDS['Right'])
                coordinates = rotate_right(coordinates)
            if x > 0:
                client.execute_command(COMMANDS['Left'])
                coordinates = rotate_left(coordinates)
