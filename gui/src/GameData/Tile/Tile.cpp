//
// Created by Tomi-Tom on 6/12/23.
//

#include "Tile.hpp"

void Tile::display(sf::RenderWindow &window) {
    sf::RectangleShape tile(_size);
    tile.setPosition(_position);
    tile.setFillColor(_color);
    tile.setOutlineColor(_borderColor);
    tile.setOutlineThickness(1);
    window.draw(tile);
}

void Tile::updateRessource(Ressource ressource, Operation operation, std::size_t value) {
    if (operation == Operation::INC)
        _ressources[ressource] += value;
    else
        _ressources[ressource] -= value;
}