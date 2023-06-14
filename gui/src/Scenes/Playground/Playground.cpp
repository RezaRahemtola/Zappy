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
        std::vector<std::vector<std::size_t>> map = _client.mct();
        for (std::size_t i = 0; i < map.size(); i++) {
            std::cout << "tile " << i % 10 << " " << i / 10 << " : ";
            for (std::size_t j = 0; j < map[i].size(); j++) {
                std::cout << map[i][j] << " ";
            }
            std::cout << std::endl;
        }
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
    _gameData.display(window);
    _playButton.display(window);
    _quitButton.display(window);
    _pauseButton.display(window);
}
