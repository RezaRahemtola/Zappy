/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Egg.hpp
*/

#ifndef EGG_HPP_
	#define EGG_HPP_

#include <raylib.h>

class Egg {
	public:
		Egg(Vector2 position, std::size_t id, std::size_t teamId) :
            _id(id), _teamId(teamId), _position(Vector3 {position.x, position.y, 0}) {};
		~Egg() {};

        void display();

        std::size_t getId() const { return _id; }

	private:
        std::size_t _id;
        std::size_t _teamId;

        // Graphical information
        Vector3 _position;
};

#endif /*EGG_HPP_*/