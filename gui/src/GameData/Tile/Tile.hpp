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
        Tile(std::size_t x, std::size_t y, std::size_t size, sf::Vector2f margin) :
            _position(sf::Vector2f(x, y)), _size(size), _margin(margin) {

            _position.x = _position.x * _size + _margin.x;
            _position.y = _position.y * _size + _margin.y;
            _font.loadFromFile("assets/fonts/arial.ttf");
            _ressources[Ressource::FOOD] = 5;
            _ressources[Ressource::LINEMATE] = 5;
            _ressources[Ressource::DERAUMERE] = 5;
            _ressources[Ressource::SIBUR] = 0;
            _ressources[Ressource::MENDIANE] = 0;
            _ressources[Ressource::PHIRAS] = 0;
            _ressources[Ressource::THYSTAME] = 0;
        }
        ~Tile() = default;

        void display(sf::RenderWindow &window);

        std::size_t getRessource(Ressource ressource);
        void updateRessource(Ressource ressource, Operation operation, std::size_t value);

    private:
        // Information
        sf::Vector2f _position;
        std::size_t _size;
        sf::Vector2f _margin;
        sf::Color _color;
        sf::Color _borderColor;

        // Content
        std::unordered_map<Ressource, int> _ressources;
        sf::Font _font;

        void dislpayRessources(sf::RenderWindow &window);
};

#endif /*TILE_HPP_*/
