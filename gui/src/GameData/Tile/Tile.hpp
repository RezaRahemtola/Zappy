/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** Tile.hpp
*/

#ifndef TILE_HPP_
#define TILE_HPP_

#include <raylib.h>
#include <unordered_map>

enum class Operation {
    INC,
    DEC
};

enum class Ressource {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

class Tile {
    public:
        Tile(Vector2 position, std::size_t size) :
            _position(Vector3 {position.x * _size , 0, position.y * _size}), _size(size) {

            _mesh = GenMeshCube(size, size/2, size);

            _fontSize = size / 5;

            _ressources[Ressource::FOOD] = 5;
            _ressources[Ressource::LINEMATE] = 5;
            _ressources[Ressource::DERAUMERE] = 5;
            _ressources[Ressource::SIBUR] = 0;
            _ressources[Ressource::MENDIANE] = 0;
            _ressources[Ressource::PHIRAS] = 0;
            _ressources[Ressource::THYSTAME] = 0;
        }
        ~Tile() = default;

        void display();

        std::size_t getRessource(Ressource ressource);
        void updateRessource(Ressource ressource, Operation operation, std::size_t value);

    private:
        // Information
        std::size_t _size;

        // Content
        std::unordered_map<Ressource, int> _ressources;
        std::size_t _fontSize;

        // Graphical information
        Vector3 _position;
        Mesh _mesh;

        void dislpayRessources();
};

#endif /*TILE_HPP_*/
