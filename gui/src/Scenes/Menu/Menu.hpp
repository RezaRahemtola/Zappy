/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP_
	#define MENU_HPP_

    #include <iostream>
    #include <SFML/Graphics.hpp>
    #include "IDisplay.hpp"
    #include "Button.hpp"

class Menu : public IDisplay {
    public:
        Menu() {
            sf::Color color = sf::Color(235, 158, 50);

            // UI Setup
            _background = sf::RectangleShape(sf::Vector2f(1920, 1080));
            _background.setFillColor(sf::Color(48, 43, 52));
            _buttonContainer = sf::RectangleShape(sf::Vector2f(500, 1080));
            _buttonContainer.setFillColor(sf::Color(63, 57, 68));

            // Buttons setup
            _playButton = Button("Play", sf::Vector2f(100, 100), sf::Vector2f(250, 75), color);
            _quitButton = Button("Quit", sf::Vector2f(100, 800), sf::Vector2f(250, 75), color);

        };
        ~Menu() override {};

        std::string run(sf::RenderWindow &window) override;
        void display(sf::RenderWindow &window) override;

    private:
        // Buttons
        Button _playButton;
        Button _quitButton;

        // Components UI
        sf::RectangleShape _background;
        sf::RectangleShape _buttonContainer;
};

#endif /*MENU_HPP_*/
