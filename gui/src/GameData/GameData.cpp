/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** GameData.cpp
*/

#include <iostream>
#include "GameData.hpp"

void GameData::display(sf::RenderWindow &window) {
    for (auto &line : _tiles)
        for (auto &tile : line)
            tile.display(window);
}

void GameData::updateMapSize(std::size_t width, std::size_t height) {
    _width = width;
    _height = height;
    std::size_t size_base = 1900 / _width > 900 / _height ? 900 / _height : 1900 / _width;
    sf::Vector2f margin((1900 - size_base * _width) / 2, (900 - size_base * _height) / 2);

    if (_tiles.size() != 0)
        return;
    for (std::size_t y = 0; y < _height; y++) {
        std::vector<Tile> line;

        for (std::size_t x = 0; x < _width; x++) {
            std::cout << "size base : " << size_base << std::endl;
            line.emplace_back(Tile(x, y, size_base, margin));
        }
        _tiles.push_back(line);
    }
}

void GameData::updateRessources(std::vector <std::string> &tileData) {
    std::size_t x = std::stoi(tileData[1]);
    std::size_t y = std::stoi(tileData[2]);

    updateRessource(x, y, Ressource::FOOD, std::stoi(tileData[3]));
    updateRessource(x, y, Ressource::LINEMATE, std::stoi(tileData[4]));
    updateRessource(x, y, Ressource::DERAUMERE, std::stoi(tileData[5]));
    updateRessource(x, y, Ressource::SIBUR, std::stoi(tileData[6]));
    updateRessource(x, y, Ressource::MENDIANE, std::stoi(tileData[7]));
    updateRessource(x, y, Ressource::PHIRAS, std::stoi(tileData[8]));
    updateRessource(x, y, Ressource::THYSTAME, std::stoi(tileData[9]));
}

void GameData::updateRessource(std::size_t x, std::size_t y, Ressource ressource, std::size_t value) {
    std::size_t currentRessource = _tiles[y][x].getRessource(ressource);

    if (currentRessource < value)
        _tiles[y][x].updateRessource(ressource, Operation::INC, value - currentRessource);
    else
        _tiles[y][x].updateRessource(ressource, Operation::DEC, currentRessource - value);
}
