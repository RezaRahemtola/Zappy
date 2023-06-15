from ai_client import AIClient, COMMANDS
from typing import List, Tuple


def move_forward(coordinates: list[tuple[int, int]]) -> tuple[int, int]:
    for i in range(len(coordinates)):
        coordinates[i] = (coordinates[i][0], coordinates[i][1] + 1)


def rotate_right(coordinates: list[tuple[int, int]]) -> list[tuple[int, int]]:
    for i in range(len(coordinates)):
        x, y = coordinates[i]
        coordinates[i] = (y, -x)
    return coordinates


def rotate_left(coordinates: list[tuple[int, int]]) -> list[tuple[int, int]]:
    for i in range(len(coordinates)):
        x, y = coordinates[i]
        coordinates[i] = (-y, x)
    return coordinates


def travel(client: AIClient, coordinates: list[tuple[int, int]]) -> None:
    while coordinates:
        x, y = coordinates[i]
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
            if x > 0:
                client.execute_command(COMMANDS['Right'])
                coordinates = rotate_right(coordinates)
            if x < 0:
                client.execute_command(COMMANDS['Left'])
                coordinates = rotate_left(coordinates)
