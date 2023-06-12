/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** Tile.cpp
*/

#include "Tile.hpp"

void Tile::display(sf::RenderWindow &window) {
    sf::RectangleShape border(_size);
    sf::RectangleShape tile(sf::Vector2f(_size.x - 2, _size.y - 2));

    border.setPosition(_position);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(1);
    border.setOutlineColor(sf::Color::Black);
    tile.setPosition(_position.x + 1, _position.y + 1);
    tile.setFillColor(sf::Color::Green);
    window.draw(border);
    window.draw(tile);
    dislpayRessources(window);
}

void Tile::dislpayRessources(sf::RenderWindow &window) {
    sf::RectangleShape food(sf::Vector2f(_size.x / 5, _size.y / 5));
    sf::RectangleShape linemate(sf::Vector2f(_size.x / 5, _size.y / 5));
    sf::RectangleShape deraumere(sf::Vector2f(_size.x / 5, _size.y / 5));
    sf::RectangleShape sibur(sf::Vector2f(_size.x / 5, _size.y / 5));
    sf::RectangleShape mendiane(sf::Vector2f(_size.x / 5, _size.y / 5));
    sf::RectangleShape phiras(sf::Vector2f(_size.x / 5, _size.y / 5));
    sf::RectangleShape thystame(sf::Vector2f(_size.x / 5, _size.y / 5));

    sf::Text foodText(std::to_string(_ressources[Ressource::FOOD]), _font, 20);
    sf::Text linemateText(std::to_string(_ressources[Ressource::LINEMATE]), _font, 20);
    sf::Text deraumereText(std::to_string(_ressources[Ressource::DERAUMERE]), _font, 20);
    sf::Text siburText(std::to_string(_ressources[Ressource::SIBUR]), _font, 20);
    sf::Text mendianeText(std::to_string(_ressources[Ressource::MENDIANE]), _font, 20);
    sf::Text phirasText(std::to_string(_ressources[Ressource::PHIRAS]), _font, 20);
    sf::Text thystameText(std::to_string(_ressources[Ressource::THYSTAME]), _font, 20);

    food.setPosition(_position.x + 1, _position.y + 1);
    food.setFillColor(sf::Color::Red);
    foodText.setPosition(_position.x + 4, _position.y - 3);
    foodText.setFillColor(sf::Color::Black);

    linemate.setPosition(_position.x + 1, _position.y + 1 + (_size.y / 5));
    linemate.setFillColor(sf::Color::Blue);
    linemateText.setPosition(_position.x + 1, _position.y - 3 + _size.y / 5);
    linemateText.setFillColor(sf::Color::Black);

    deraumere.setPosition(_position.x + 1, _position.y + 1 + _size.y / 5 * 2);
    deraumere.setFillColor(sf::Color(139, 69, 19));
    deraumereText.setPosition(_position.x + 1, _position.y + 1 + _size.y / 5 * 2);
    deraumereText.setFillColor(sf::Color::Black);

    sibur.setPosition(_position.x + 1, _position.y + 1 + _size.y / 5 * 3);
    sibur.setFillColor(sf::Color(255, 165, 0));
    siburText.setPosition(_position.x + 1, _position.y + 1 + _size.y / 10 + _size.y / 5 * 3);
    siburText.setFillColor(sf::Color::Black);

    mendiane.setPosition(_position.x + 1, _position.y + 1 + _size.y / 5 * 4);
    mendiane.setFillColor(sf::Color::Magenta);
    mendianeText.setPosition(_position.x + 1, _position.y + 1 + _size.y / 10 + _size.y / 5 * 4);
    mendianeText.setFillColor(sf::Color::Black);

    phiras.setPosition(_position.x + 1 + _size.x / 5, _position.y + 1);
    phiras.setFillColor(sf::Color::Cyan);
    phirasText.setPosition(_position.x + 1 + _size.x / 10 + _size.x / 5, _position.y - 3);
    phirasText.setFillColor(sf::Color::Black);

    thystame.setPosition(_position.x + 1 + _size.x / 5, _position.y + 1 + _size.y / 5);
    thystame.setFillColor(sf::Color::White);
    thystameText.setPosition(_position.x + 1 + _size.x / 10 + _size.x / 5, _position.y - 3 + _size.y / 5);
    thystameText.setFillColor(sf::Color::Black);

    window.draw(food);
    window.draw(linemate);
    window.draw(deraumere);
    window.draw(sibur);
    window.draw(mendiane);
    window.draw(phiras);
    window.draw(thystame);

    window.draw(foodText);
    window.draw(linemateText);
    window.draw(deraumereText);
    window.draw(siburText);
    window.draw(mendianeText);
    window.draw(phirasText);
    window.draw(thystameText);
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
