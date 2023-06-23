/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** GameData.cpp
*/

#include <iostream>
#include "GameData.hpp"

void GameData::display() {
    for (auto &line : _tiles)
        for (auto &tile : line)
            tile.display();
    for (auto &player : _players)
        player.display();
}

void GameData::createPlayer(std::size_t id, Vector2 position, std::size_t orientation, std::size_t level, std::string teamName) {
    std::cout << "Creating player " << id << " at position " << position.x << " " << position.y << std::endl;
    position.x *= _tileSize;
    position.y *= _tileSize;

    std::cout << "Creating player " << id << " at position " << position.x << " " << position.y << std::endl;
    _players.push_back(Player(id, position));
    _players.back().setLevel(level);
    _players.back().setTeamName(teamName);
    _players.back().setOrientation(orientation);
}

std::size_t GameData::getPlayerId(std::size_t id) {
    for (auto &player : _players)
        if (player.getId() == id)
            return player.getId();
    return -1;
}

void GameData::addMessageToPlayer(std::size_t id, std::string message) {
    for (auto &player : _players)
        if (player.getId() == id)
            player.setMessage(message);
}

void GameData::deletePlayer(std::size_t id) {
    for (std::size_t i = 0; i < _players.size(); i++)
        if (_players[i].getId() == id)
            _players.erase(_players.begin() + i);
}

void GameData::createEgg(Vector2 pos, std::size_t id, std::size_t teamId) {
    _eggs.push_back(Egg(pos, id, teamId));
}

void GameData::deleteEgg(std::size_t id) {
    for (std::size_t i = 0; i < _eggs.size(); i++)
        if (_eggs[i].getId() == id)
            _eggs.erase(_eggs.begin() + i);
}

void GameData::updateMapSize(int width, int height) {
    _width = width;
    _height = height;
    _tileSize = 4;

    if (_tiles.size() != 0)
        return;
    for (int y = 0; y < _height; y++) {
        std::vector<Tile> line;

        for (int x = 0; x < _width; x++)
            line.emplace_back(Tile(Vector2(x, y), _tileSize));
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

void GameData::updatePlayerInventory(std::size_t id, std::vector<std::string> &inventory) {
    for (auto &player : _players)
        if (player.getId() == id)
            player.updateInventory(inventory);
}

void GameData::updatePlayerPosition(std::size_t id, Vector2 position, std::size_t orientation) {
    for (auto &player : _players)
        if (player.getId() == id) {
            position.x *= _tileSize;
            position.y *= _tileSize;
            player.updatePosition(position, orientation);
        }
}

void GameData::updatePlayerLevel(std::size_t id, std::size_t level) {
    for (auto &player : _players)
        if (player.getId() == id)
            player.setLevel(level);
}
