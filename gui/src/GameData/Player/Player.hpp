/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Player.hpp
*/
#ifndef PLAYER_HPP_
	#define PLAYER_HPP_

    #include <SFML/Graphics.hpp>

class Player {
	public:
		Player();
		~Player();

	private:
        sf::Vector2f _position;

        size_t _level;
        std::string _teamName;
        std::size_t _orientation;
        std::size_t _inventory[7];
        std::size_t _children;
};

#endif /*PLAYER_HPP_*/
