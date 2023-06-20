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
		Player(std::size_t id, sf::Vector2f position) : _id(id), _position(position) {};
		~Player() = default;

        void display(sf::RenderWindow &window);

        std::size_t getId() const { return _id; }

        sf::Vector2f getPosition() const { return _position; }
        void setPosition(sf::Vector2f position) { _position = position; }

        std::size_t getLevel() const { return _level; }
        void setLevel(std::size_t level) { _level = level; }

        std::string getTeamName() const { return _teamName; }
        void setTeamName(std::string teamName) { _teamName = teamName; }

        std::size_t getOrientation() const { return _orientation; }
        void setOrientation(std::size_t orientation) { _orientation = orientation; }

        std::string getMessage() const { return _message; }
        void setMessage(std::string message) { _message = message; }

        void updateInventory(std::vector<std::string> &inventory);
        void updateResource(std::size_t resource, int value);
        void updatePosition(std::vector<std::string> &position);
        void updateLevel(size_t level) { _level = level; }
        void startIncantation() { _elevation = true; }
        void endIncantation() { _elevation = false; }

	private:
        // Information
        std::size_t _id;
        size_t _level;
        std::string _teamName;
        std::size_t _orientation;
        std::size_t _inventory[7];
        std::size_t _children;
        bool _elevation = false;
        std::string _message;

        // Graphical information
        sf::Vector2f _position;
        sf::Texture _texture;
        sf::Sprite _sprite;
};

#endif /*PLAYER_HPP_*/
