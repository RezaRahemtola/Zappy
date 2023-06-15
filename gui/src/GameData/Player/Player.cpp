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