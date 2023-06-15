/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Playground.cpp
*/

#include "Playground.hpp"

void Playground::handlePause() {
    if (_playButton.isClicked())
        _pause = false;
    if (_pauseButton.isClicked())
        _pause = true;
}

std::string Playground::run(sf::RenderWindow &window) {
    // run simulation
    handlePause();
    if (!_pause) {
        _client.handleDataServer();
        // mettre a jour les choses hors pause
    }
    display(window);
    if (_quitButton.isClicked())
        return "Menu";
    return "Playground";
}

void Playground::display(sf::RenderWindow &window) {
    window.draw(_background);
    window.draw(_ButtonContainer);
    _gameData->display(window);
    _playButton.display(window);
    _quitButton.display(window);
    _pauseButton.display(window);
}
