/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Egg.cpp
*/

#include "Egg.hpp"

void Egg::display(sf::RenderWindow &window)
{
    _texture.loadFromFile("assets/sprites/egg.png");
    _sprite.setTexture(_texture);
    _sprite.setScale(sf::Vector2f(0.1, 0.1));
    _sprite.setPosition(_position);

    window.draw(_sprite);
}
