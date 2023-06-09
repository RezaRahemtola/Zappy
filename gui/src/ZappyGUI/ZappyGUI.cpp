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
    std::vector<std::string> messageQueue;

    while (_window.isOpen()) {
        std::cout << "SENDING REQUESTS :" << std::endl;
        _client.sendRequest("msz\n");
        _client.sendRequest("bct 0 0\n");
        _client.sendRequest("mct\n");
        _client.sendRequest("tna\n");
        _client.sendRequest("ppo 0\n");
        _client.sendRequest("plv 0\n");
        _client.sendRequest("pin 0\n");
        _client.sendRequest("sgt\n");
        _client.collectMessage();
        pollEvents();
        _window.clear();
        if (_currentDisplay != "Quit")
            _currentDisplay = _displays[_currentDisplay]->run(_window);
        _window.display();
        messageQueue = _client.getMessageQueue();
        std::cout << "RECEIVING MESSAGES :" << std::endl;
        for (auto &message : messageQueue) {
            std::cout << " - recieved : " << message << std::endl;
        }
    }
}