/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Egg.hpp
*/

#ifndef EGG_HPP_
	#define EGG_HPP_

#include <SFML/Graphics.hpp>

class Egg {
	public:
		Egg() {};
		~Egg() {};

	private:
        std::size_t _id;
        std::size_t _teamId;
        sf::Vector2f _position;
};

#endif /*EGG_HPP_*/