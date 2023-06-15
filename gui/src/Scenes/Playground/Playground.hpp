/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Playground.hpp
*/

#ifndef PLAYGROUND_HPP_
	#define PLAYGROUND_HPP_

    #include <SFML/Graphics.hpp>
    #include <memory>
    #include "ClientGUI.hpp"
    #include "IDisplay.hpp"
    #include "Button.hpp"
    #include "GameData.hpp"

class Playground : public IDisplay {
    public:
        Playground(std::string machine, std::size_t port) : _gameData(std::make_shared<GameData>()), _port(port), _machine(machine),
            _client(ClientGUI(machine, port, _gameData)), _pause(false) {

            // Color setup
            sf::Color color = sf::Color(253, 217, 163);

            // UI setup
            _background = sf::RectangleShape(sf::Vector2f(1920, 1080));
            _background.setFillColor(sf::Color(48, 43, 52));
            _ButtonContainer = sf::RectangleShape(sf::Vector2f(1920, 200));
            _ButtonContainer.setPosition(sf::Vector2f(0, 920));
            _ButtonContainer.setFillColor(sf::Color(63, 57, 68));

            // Buttons setup
            _playButton = Button("Play", sf::Vector2f(50, 950), sf::Vector2f(100, 50), color);
            _pauseButton = Button("Pause", sf::Vector2f(160, 950), sf::Vector2f(100, 50), color);
            _quitButton = Button("Quit", sf::Vector2f(1650, 950), sf::Vector2f(200, 50), color);
        };
        ~Playground() override {};

        std::string run(sf::RenderWindow &window) override;
        void display(sf::RenderWindow &window) override;

    private:
        // Content
        std::shared_ptr<GameData> _gameData;

        // Network
        int _port;
        std::string _machine;
        ClientGUI _client;

        // UI Components
        sf::RectangleShape _background;
        sf::RectangleShape _ButtonContainer;

        // Buttons
        Button _pauseButton;
        Button _playButton;
        Button _quitButton;

        // Utils
        bool _pause;
        void handlePause();

};

#endif /*PLAYGROUND_HPP_*/
