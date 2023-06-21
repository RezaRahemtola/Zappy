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
    #include "Egg.hpp"
    #include "Tokenize.hpp"

class GameData{
    public:
        GameData() : _width(0), _height(0), _tileSize(0), _margin(sf::Vector2f(0, 0)) {};
        ~GameData() = default;

        void display(sf::RenderWindow &window);

        void createPlayer(std::size_t id, size_t x, size_t y, size_t orientation, size_t level, std::string teamName);
        std::size_t getPlayerId(std::size_t id);
        void addMessageToPlayer(std::size_t id, std::string message);
        void deletePlayer(std::size_t id);
        void updatePlayerInventory(std::size_t id, std::vector<std::string> &inventory);
        void updatePlayerPosition(std::size_t id, std::vector<std::string> &position);
        void updatePlayerLevel(std::size_t id, std::size_t level);
        void startIncantation(std::vector<std::string> &ids);
        void endIncantation(int x, int y);

        void createEgg(sf::Vector2f pos, std::size_t id, std::size_t teamId);
        void deleteEgg(std::size_t id);

        void updateMapSize(size_t width, size_t height);
        void updateRessources(std::vector<std::string> &data);
        void collectResource(std::size_t id, int ressource);
        void dropResource(std::size_t id, int ressource);

    private:
        // Information
        std::size_t _width;
        std::size_t _height;
        std::size_t _tileSize;
        sf::Vector2f _margin;

        // Content
        std::vector<std::vector<Tile>> _tiles;
        std::vector<Player> _players;
        std::vector<Egg> _eggs;

        // Private methods
        void updateRessource(std::size_t x, std::size_t y, Ressource ressource, std::size_t value);
};

#endif /*GAMEDATA_HPP_*/
