/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Playground.hpp
*/

#ifndef PLAYGROUND_HPP_
	#define PLAYGROUND_HPP_

    #include <raylib.h>
    #include <memory>
    #include "ClientGUI.hpp"
    #include "IDisplay.hpp"
    #include "Button.hpp"
    #include "GameData.hpp"

class Playground : public IDisplay {
    public:
        Playground(std::string machine, std::size_t port) : _gameData(std::make_shared<GameData>()), _port(port), _machine(machine),
            _client(ClientGUI(machine, port, _gameData)), _pause(false) {

        };
        ~Playground() override {};

        std::string run() override;
        void display() override;

        std::unordered_map<Ressource, int> getRessources(Ray ray) { return _gameData->getRessourcesFromSelectedTile(ray); };

    private:
        // Content
        std::shared_ptr<GameData> _gameData;

        // Network
        int _port;
        std::string _machine;
        ClientGUI _client;

        // Utils
        bool _pause;
        void handlePause();

        // Graphical elements
        Ray _ray;

};

#endif /*PLAYGROUND_HPP_*/
