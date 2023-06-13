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
    ZappyGUI(std::string machine, std::size_t port) : _window(sf::VideoMode(1920, 1020), "Zappy") {
        _displays["Menu"] = std::make_unique<Menu>();
        _displays["Playground"] = std::make_unique<Playground>(machine, port);
        _currentDisplay = "Playground";
    }
    ~ZappyGUI() { };

    void run();

private:

    // Graphical
    sf::RenderWindow _window;
    sf::Event _event;
    std::unordered_map<std::string, std::unique_ptr<IDisplay>> _displays;
    std::string _currentDisplay;

    void pollEvents();
};

#endif /*SIMULATION_HPP_*/
