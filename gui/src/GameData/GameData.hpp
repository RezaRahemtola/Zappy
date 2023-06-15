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
    #include "Player.hpp"
    #include "Tokenize.hpp"

class GameData{
    public:
        GameData() {};
        ~GameData() = default;

        void display(sf::RenderWindow &window);

        void updateMapSize(size_t width, size_t height);
        void updateRessources(std::vector<std::string> &data);

    private:
        // Information
        std::size_t _width;
        std::size_t _height;

        // Content
        std::vector<std::vector<Tile>> _tiles;
        std::vector<Player> _players;

        // Private methods
        void updateRessource(std::size_t x, std::size_t y, Ressource ressource, std::size_t value);
};

#endif /*GAMEDATA_HPP_*/
