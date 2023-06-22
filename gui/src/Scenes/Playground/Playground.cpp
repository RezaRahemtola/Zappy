/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Playground.cpp
*/

#include "Playground.hpp"

void Playground::handlePause() {

}

std::string Playground::run() {
    handlePause();
    if (!_pause) {
        _client.handleDataServer();
        // mettre a jour les choses hors pause
    }
    display();
    if (IsKeyPressed(KEY_ESCAPE))
        return "Menu";
    return "Playground";
}

void Playground::display() {
    _gameData->display();
}
