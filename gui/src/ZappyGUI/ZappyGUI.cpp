/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ZappyGUI.cpp
*/

#include <iostream>
#include "ZappyGUI.hpp"

void ZappyGUI::pollEvents() {
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
    }
    if (_currentDisplay == "Quit")
        _window.close();
}

void ZappyGUI::run() {
    std::string data;

    while (_window.isOpen()) {
        _client.sending("msz\n");
        _client.receive(data);
        std::cout << "Data Received : " << data;
        pollEvents();
        _window.clear();
        if (_currentDisplay != "Quit")
            _currentDisplay = _displays[_currentDisplay]->run(_window);
        _window.display();
    }
}