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
		Player() {
            _texture.loadFromFile("assets/sprites/player.png");
            _sprite.setTexture(_texture);
            _sprite.setScale(sf::Vector2f(0.5, 0.5));
        }
		~Player();

        void display(sf::RenderWindow &window);

        sf::Vector2f getPosition() const { return _position; }
        void setPosition(sf::Vector2f position) { _position = position; }

	private:
        // Information
        std::size_t _id;
        size_t _level;
        std::string _teamName;
        std::size_t _orientation;
        std::size_t _inventory[7];
        std::size_t _children;

        // Graphical information
        sf::Vector2f _position;
        sf::Texture _texture;
        sf::Sprite _sprite;


};

#endif /*PLAYER_HPP_*/
