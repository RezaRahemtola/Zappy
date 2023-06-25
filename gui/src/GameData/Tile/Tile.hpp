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
        Tile(Vector2 position, std::size_t size) : _size(size),
            _position(Vector3 {position.x * _size , 0, position.y * _size}), _selected(true) {

            _mesh = GenMeshCube(size, size/2, size);

            _fontSize = size / 5;

            _ressources[Ressource::FOOD] = 0;
            _ressources[Ressource::LINEMATE] = 0;
            _ressources[Ressource::DERAUMERE] = 0;
            _ressources[Ressource::SIBUR] = 0;
            _ressources[Ressource::MENDIANE] = 0;
            _ressources[Ressource::PHIRAS] = 0;
            _ressources[Ressource::THYSTAME] = 0;

            Vector2 ressourcePosition = Vector2 {(static_cast<float>(rand() % 100) / 100), static_cast<float>(rand() % 100) / 100};
            _ressourcesPosition[Ressource::FOOD] = ressourcePosition;
            ressourcePosition = Vector2 {static_cast<float>(rand() % 100) / 100, static_cast<float>(rand() % 100) / 100};
            _ressourcesPosition[Ressource::LINEMATE] = ressourcePosition;
            ressourcePosition = Vector2 {static_cast<float>(rand() % 100) / 100, static_cast<float>(rand() % 100) / 100};
            _ressourcesPosition[Ressource::DERAUMERE] = ressourcePosition;
            ressourcePosition = Vector2 {static_cast<float>(rand() % 100) / 100, static_cast<float>(rand() % 100) / 100};
            _ressourcesPosition[Ressource::SIBUR] = ressourcePosition;
            ressourcePosition = Vector2 {static_cast<float>(rand() % 100) / 100, static_cast<float>(rand() % 100) / 100};
            _ressourcesPosition[Ressource::MENDIANE] = ressourcePosition;
            ressourcePosition = Vector2 {static_cast<float>(rand() % 100) / 100, static_cast<float>(rand() % 100) / 100};
            _ressourcesPosition[Ressource::PHIRAS] = ressourcePosition;
            ressourcePosition = Vector2 {static_cast<float>(rand() % 100) / 100, static_cast<float>(rand() % 100) / 100};
            _ressourcesPosition[Ressource::THYSTAME] = ressourcePosition;

            _boundingBox = BoundingBox {_position, Vector3 {_position.x + _size, _position.y + (_size / 2), _position.z + _size}};
        }
        ~Tile() = default;

        void display();
        void displayRessources();

        std::size_t getRessource(Ressource ressource);
        void updateRessource(Ressource ressource, Operation operation, std::size_t value);

        BoundingBox getBoundingBox() { return _boundingBox; };

    private:
        // Information
        std::size_t _size;

        // Content
        std::unordered_map<Ressource, int> _ressources;
        std::unordered_map<Ressource, Vector2> _ressourcesPosition;

        std::size_t _fontSize;

        // Graphical information
        Vector3 _position;
        Mesh _mesh;
        BoundingBox _boundingBox;

        bool _selected;

        void dislpayRessources();
};

#endif /*TILE_HPP_*/
