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
    

    DrawCubeWires(_position, _size + 0.2, _size/2 + 0.1, _size + 0.2, RED);
}

void Tile::dislpayRessources() {

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
