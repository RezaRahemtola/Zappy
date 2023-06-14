/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** GameData.hpp
*/

#ifndef GAMEDATA_HPP_
	#define GAMEDATA_HPP_

    #include <vector>
    #include "Tile.hpp"
    #include "Tokenize.hpp"

class GameData{
    public:
        GameData() = default;
        GameData(std::size_t width, std::size_t height) {
            _width = width;
            _height = height;

            for (std::size_t i = 0; i < _height; i++) {
                std::vector<Tile> line;
                for (std::size_t j = 0; j < _width; j++) {
                    line.push_back(Tile(j * 90, i * 90, 90));
                }
                _tiles.push_back(line);
            }
        };
        ~GameData() = default;

        void display(sf::RenderWindow &window);

        void updateRessources(std::vector<std::string> &data);

    private:
        // Information
        std::size_t _width;
        std::size_t _height;

        // Content
        std::vector<std::vector<Tile>> _tiles;

        // Private methods
        void updateRessource(std::size_t x, std::size_t y, Ressource ressource, std::size_t value);
};

#endif /*GAMEDATA_HPP_*/
