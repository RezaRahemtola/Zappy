/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Player.cpp
*/

#include "Player.hpp"

void Player::display() {
    if (_elevation) {
        DrawCube(_position, 0.5, 2, 0.5, WHITE);
        Vector3 head = Vector3 {_position.x, _position.y + 1, _position.z};
        DrawCube(head, 1, 1, 1, WHITE);
    } else {
        DrawCube(_position, 0.5, 2, 0.5, RED);
        Vector3 head = Vector3 {_position.x, _position.y + 1, _position.z};
        DrawCube(head, 1, 1, 1, RED);
    }
}

void Player::updateInventory(std::vector<std::string> &inventory) {
    _inventory[0] = std::stoi(inventory[4]);
    _inventory[1] = std::stoi(inventory[5]);
    _inventory[2] = std::stoi(inventory[6]);
    _inventory[3] = std::stoi(inventory[7]);
    _inventory[4] = std::stoi(inventory[8]);
    _inventory[5] = std::stoi(inventory[9]);
    _inventory[6] = std::stoi(inventory[10]);
}

void Player::updatePosition(Vector2 position, std::size_t orientation) {
    _position.x = position.x;
    _position.z = position.y;
    _orientation = orientation;
}
