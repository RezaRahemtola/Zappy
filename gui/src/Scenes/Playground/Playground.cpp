//
// Created by Tomi-Tom on 3/29/23.
//

#include "Playground.hpp"

void Playground::handlePause() {
    if (_playButton.isClicked())
        _pause = false;
    if (_pauseButton.isClicked())
        _pause = true;
}

std::string Playground::run(sf::RenderWindow &window) {
    // run simulation
    comunicateWithServer();
    handleData();
    handlePause();
    if (!_pause) {
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
    _playButton.display(window);
    _quitButton.display(window);
    _pauseButton.display(window);
}

void Playground::comunicateWithServer() {
    std::string data1;
    std::string data2;

    _client.receive(data1);
    _buffer += data1;
    _client.sending("msz\n");
    _client.sending("mct\n");
    _client.sending("tna\n");
    sleep(1);
    _client.receive(data2);
    _buffer += data2;
}

void Playground::handleData() {
    std::vector<std::string> lines;
    tokenize(_buffer, '\n', lines);
}
