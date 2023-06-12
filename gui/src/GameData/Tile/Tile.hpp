/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** Tile.hpp
*/
#ifndef TILE_HPP_
#define TILE_HPP_

#include <SFML/Graphics.hpp>
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
    Tile(int x, int y, int size) : _position(sf::Vector2f(x, y)), _size(sf::Vector2f(size, size)) {
        _ressources[Ressource::FOOD] = 0;
        _ressources[Ressource::LINEMATE] = 0;
        _ressources[Ressource::DERAUMERE] = 0;
        _ressources[Ressource::SIBUR] = 0;
        _ressources[Ressource::MENDIANE] = 0;
        _ressources[Ressource::PHIRAS] = 0;
        _ressources[Ressource::THYSTAME] = 0;
    }
    ~Tile();

    void display(sf::RenderWindow &window);

    std::size_t getRessource(Ressource ressource);
    void updateRessource(Ressource ressource, Operation operation, std::size_t value);

private:
    // information
    sf::Vector2f _position;
    sf::Vector2f _size;
    sf::Color _color;
    sf::Color _borderColor;

    // content
    std::unordered_map<Ressource, int> _ressources;

};

#endif /*TILE_HPP_*/