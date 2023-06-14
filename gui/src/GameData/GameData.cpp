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

void GameData::updateRessources(std::vector <std::string> &data) {
    for (auto &line : data) {
        std::vector<std::string> tileData;
        tokenize(line, ' ', tileData);
        std::size_t x = std::stoi(tileData[0]);
        std::size_t y = std::stoi(tileData[1]);

        updateRessource(x, y, Ressource::FOOD, std::stoi(tileData[2]));
        updateRessource(x, y, Ressource::LINEMATE, std::stoi(tileData[3]));
        updateRessource(x, y, Ressource::DERAUMERE, std::stoi(tileData[4]));
        updateRessource(x, y, Ressource::SIBUR, std::stoi(tileData[5]));
        updateRessource(x, y, Ressource::MENDIANE, std::stoi(tileData[6]));
        updateRessource(x, y, Ressource::PHIRAS, std::stoi(tileData[7]));
        updateRessource(x, y, Ressource::THYSTAME, std::stoi(tileData[8]));
    }
}

void GameData::updateRessource(std::size_t x, std::size_t y, Ressource ressource, std::size_t value) {
    std::size_t currentRessource = _tiles[y][x].getRessource(ressource);

    if (currentRessource < value)
        _tiles[y][x].updateRessource(ressource, Operation::INC, value - currentRessource);
    else
        _tiles[y][x].updateRessource(ressource, Operation::DEC, currentRessource - value);
}
