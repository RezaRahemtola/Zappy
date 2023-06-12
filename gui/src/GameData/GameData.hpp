/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** GameData.hpp
*/
#ifndef GAMEDATA_HPP_
	#define GAMEDATA_HPP_

#include <vector>
#include "Tile/Tile.hpp"

class GameData{
public:
    GameData();
    ~GameData();

private:
    std::size_t _width;
    std::size_t _height;
    std::vector<std::vector<Tile>> _tiles;

};

#endif /*GAMEDATA_HPP_*/