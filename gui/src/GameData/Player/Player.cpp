/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Player.cpp
*/

#include "Player.hpp"

void Player::display(sf::RenderWindow &window)
{
    _texture.loadFromFile("assets/sprites/player.png");
    _sprite.setTexture(_texture);
    _sprite.setScale(sf::Vector2f(0.1, 0.1));
    _sprite.setPosition(_position);

    window.draw(_sprite);
}

void Player::updateInventory(std::vector<std::string> &inventory)
{
    _inventory[0] = std::stoi(inventory[4]);
    _inventory[1] = std::stoi(inventory[5]);
    _inventory[2] = std::stoi(inventory[6]);
    _inventory[3] = std::stoi(inventory[7]);
    _inventory[4] = std::stoi(inventory[8]);
    _inventory[5] = std::stoi(inventory[9]);
    _inventory[6] = std::stoi(inventory[10]);
}