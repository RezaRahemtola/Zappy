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
		Egg(sf::Vector2f position, std::size_t id, std::size_t teamId) :
            _id(id), _teamId(teamId), _position(position) {};
		~Egg() {};

        void display(sf::RenderWindow &window);

        std::size_t getId() const { return _id; }

	private:
        std::size_t _id;
        std::size_t _teamId;

        // Graphical information
        sf::Vector2f _position;
        sf::Texture _texture;
        sf::Sprite _sprite;
};

#endif /*EGG_HPP_*/