/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Player.cpp
*/

#include "Player.hpp"

void Player::display(sf::RenderWindow &window)
{
    _sprite.setPosition(_position);

    window.draw(_sprite);
}