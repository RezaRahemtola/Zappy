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
    for (auto &player : _players)
        player.display(window);
}

void GameData::createPlayer(std::size_t id, size_t x, size_t y, size_t orientation, size_t level, std::string teamName) {
    _players.push_back(Player(id, sf::Vector2f(x * _tileSize + _margin.x + 30, y * _tileSize + _margin.y + 30)));
    _players.back().setLevel(level);
    _players.back().setTeamName(teamName);
    _players.back().setOrientation(orientation);
}

void GameData::deletePlayer(std::size_t id) {
    for (std::size_t i = 0; i < _players.size(); i++)
        if (_players[i].getId() == id)
            _players.erase(_players.begin() + i);
}

void GameData::createEgg(sf::Vector2f pos, std::size_t id, std::size_t teamId) {
    _eggs.push_back(Egg(pos, id, teamId));
}

void GameData::deleteEgg(std::size_t id) {
    for (std::size_t i = 0; i < _eggs.size(); i++)
        if (_eggs[i].getId() == id)
            _eggs.erase(_eggs.begin() + i);
}

void GameData::updateMapSize(std::size_t width, std::size_t height) {
    _width = width;
    _height = height;
    _tileSize = 1900 / _width > 900 / _height ? 900 / _height : 1900 / _width;
    _margin = sf::Vector2f((1900 - _width * _tileSize) / 2, (900 - _height * _tileSize) / 2);

    if (_tiles.size() != 0)
        return;
    for (std::size_t y = 0; y < _height; y++) {
        std::vector<Tile> line;

        for (std::size_t x = 0; x < _width; x++)
            line.emplace_back(Tile(x, y, _tileSize, _margin));
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
