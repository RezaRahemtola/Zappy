/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ZappyGUI.hpp
*/
#ifndef SIMULATION_HPP_
	#define SIMULATION_HPP_

    #include <SFML/Graphics.hpp>
    #include <unordered_map>
    #include <memory>
    #include "IDisplay.hpp"
    #include "Menu.hpp"
    #include "Playground.hpp"

class ZappyGUI {
public:
    ZappyGUI() : _window(sf::VideoMode(1920, 1080), "Zappy") {
        _displays["Menu"] = std::make_unique<Menu>();
        _displays["Playground"] = std::make_unique<Playground>();
        _currentDisplay = "Menu";
    }
    ~ZappyGUI() { };

    void setPort(int port) { _port = port; }
    void setMachine(std::string machine) { _machine = machine; }

    void run();

private:
    // Network
    int _port;
    std::string _machine;

    // Graphical
    sf::RenderWindow _window;
    sf::Event _event;
    std::unordered_map<std::string, std::unique_ptr<IDisplay>> _displays;
    std::string _currentDisplay;

    void pollEvents();
};

#endif /*SIMULATION_HPP_*/
