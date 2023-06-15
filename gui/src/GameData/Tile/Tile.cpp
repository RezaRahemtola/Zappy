/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** Tile.cpp
*/

#include <iostream>
#include "Tile.hpp"

void Tile::display(sf::RenderWindow &window) {
    sf::RectangleShape border(sf::Vector2f(_size, _size));
    sf::RectangleShape tile(sf::Vector2f(_size - 2, _size - 2));

    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(1);
    border.setOutlineColor(sf::Color::Black);
    border.setPosition(_position.x, _position.y);
    tile.setPosition(_position.x + 1, _position.y + 1);
    tile.setFillColor(sf::Color(16, 180, 16));
    window.draw(border);
    window.draw(tile);
    dislpayRessources(window);
}

void Tile::dislpayRessources(sf::RenderWindow &window) {
    int i = 0;

    for (auto &ressource : _ressources) {
        sf::Text text;
        std::string str = std::to_string(ressource.second);

        text.setFont(_font);
        text.setString(str);
        text.setCharacterSize(_fontSize);

        if (ressource.first == Ressource::FOOD)
            text.setFillColor(sf::Color::Red);
        else if (ressource.first == Ressource::LINEMATE)
            text.setFillColor(sf::Color::Yellow);
        else if (ressource.first == Ressource::DERAUMERE)
            text.setFillColor(sf::Color::Blue);
        else if (ressource.first == Ressource::SIBUR)
            text.setFillColor(sf::Color::Magenta);
        else if (ressource.first == Ressource::MENDIANE)
            text.setFillColor(sf::Color::Cyan);
        else if (ressource.first == Ressource::PHIRAS)
            text.setFillColor(sf::Color::White);
        else if (ressource.first == Ressource::THYSTAME)
            text.setFillColor(sf::Color::Black);

        text.setPosition(_position.x + (_fontSize - 2) * (i % 5) + 5, _position.y + (_fontSize + 2) * (i / 5));
        window.draw(text);
        i++;
    }
}

void Tile::updateRessource(Ressource ressource, Operation operation, std::size_t value) {
    if (operation == Operation::INC)
        _ressources[ressource] += value;
    else
        _ressources[ressource] -= value;
}

size_t Tile::getRessource(Ressource ressource) {
    return _ressources[ressource];
}
