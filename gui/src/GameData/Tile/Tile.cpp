/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** Tile.cpp
*/

#include <iostream>
#include "Tile.hpp"

void Tile::display() {
    Material material = LoadMaterialDefault();
    Matrix transform = Matrix();

    DrawMesh(_mesh, material, transform);
    DrawCube(_position, _size, _size/2 - 0.1, _size, BLACK);
    _position.y += 0.1;
    DrawCube(_position, _size - 0.2, _size/2, _size - 0.2, GREEN);
    _position.y -= 0.1;

    displayRessources();
}

void Tile::displayRessources() {
    Vector3 position = _position;
    float ressourceSize = 0.2;

    for (auto &ressource : _ressources) {
        if (ressource.second > 0) {
            position.x += _ressourcesPosition[ressource.first].x;
            position.y = 1.1;
            position.z += _ressourcesPosition[ressource.first].y;
            if (ressource.first == Ressource::FOOD)
                DrawCube(position, ressourceSize * ressource.second, ressourceSize * ressource.second, ressourceSize * ressource.second, BEIGE);
            else if (ressource.first == Ressource::LINEMATE)
                DrawCube(position, ressourceSize * ressource.second, ressourceSize * ressource.second, ressourceSize * ressource.second, LIGHTGRAY);
            else if (ressource.first == Ressource::DERAUMERE)
                DrawCube(position, ressourceSize * ressource.second, ressourceSize * ressource.second, ressourceSize * ressource.second, YELLOW);
            else if (ressource.first == Ressource::SIBUR)
                DrawCube(position, ressourceSize * ressource.second, ressourceSize * ressource.second, ressourceSize * ressource.second, SKYBLUE);
            else if (ressource.first == Ressource::MENDIANE)
                DrawCube(position, ressourceSize * ressource.second, ressourceSize * ressource.second, ressourceSize * ressource.second, PURPLE);
            else if (ressource.first == Ressource::PHIRAS)
                DrawCube(position, ressourceSize * ressource.second, ressourceSize * ressource.second, ressourceSize * ressource.second, ORANGE);
            else if (ressource.first == Ressource::THYSTAME)
                DrawCube(position, ressourceSize * ressource.second, ressourceSize * ressource.second, ressourceSize * ressource.second, PINK);
        }
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
