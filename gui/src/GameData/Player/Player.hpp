/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Player.hpp
*/
#ifndef PLAYER_HPP_
	#define PLAYER_HPP_

    #include <iostream>
    #include <raylib.h>
    #include <vector>

class Player {
	public:
		Player(std::size_t id, Vector2 position) : _id(id), _position(Vector3 {position.x, 2, position.y}),
            _level(1), _orientation(0), _message(""), _elevation(false) {
            _inventory[0] = 0;
            _inventory[1] = 0;
            _inventory[2] = 0;
            _inventory[3] = 0;
            _inventory[4] = 0;
            _inventory[5] = 0;
            _inventory[6] = 0;
        }
		~Player() = default;

        void display();

        std::size_t getId() const { return _id; }

        Vector3 getPosition() const { return _position; }
        void setPosition(Vector3 position) { _position = position; }

        std::size_t getLevel() const { return _level; }
        void setLevel(std::size_t level) { _level = level; }

        std::string getTeamName() const { return _teamName; }
        void setTeamName(std::string teamName) { _teamName = teamName; }

        std::size_t getOrientation() const { return _orientation; }
        void setOrientation(std::size_t orientation) { _orientation = orientation; }

        std::string getMessage() const { return _message; }
        void setMessage(std::string message) { _message = message; }

        void startIncantation() { _elevation = true; }
        void endIncantation() { _elevation = false; }

        void updateInventory(std::vector<std::string> &inventory);
        void updatePosition(Vector2 position, std::size_t orientation);
        void updateLevel(size_t level) { _level = level; }

	private:
        // Information
        std::size_t _id;
        size_t _level;
        std::string _teamName;
        std::size_t _orientation;
        std::size_t _inventory[7];
        std::size_t _children;
        bool _elevation;
        std::string _message;

        // Graphical information
        Vector3 _position;
};

#endif /*PLAYER_HPP_*/
