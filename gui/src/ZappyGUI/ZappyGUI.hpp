/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ZappyGUI.hpp
*/

#ifndef SIMULATION_HPP_
	#define SIMULATION_HPP_

    #include <raylib.h>
    #include <unordered_map>
    #include <memory>
    #include "IDisplay.hpp"
    #include "Menu.hpp"
    #include "Playground.hpp"

class ZappyGUI {
    public:
        ZappyGUI(std::string machine, std::size_t port) : _width(1920), _height(1080) {
            InitWindow(_width, _height, "The ZOATIEST Project");
            _displays["Menu"] = std::make_unique<Menu>();
            _displays["Playground"] = std::make_unique<Playground>(machine, port);
            _currentDisplay = "Playground";

            SetTargetFPS(165);
            _camera = { 0 };
            _camera.position = { 10.0f, 10.0f, 10.0f };
            _camera.target = { 0.0f, 0.0f, 0.0f };
            _camera.up = { 0.0f, 1.0f, 0.0f };
            _camera.fovy = 45.0f;
            _camera.projection = CAMERA_PERSPECTIVE;
        }
        ~ZappyGUI() {
            CloseWindow();
        };

        void run();

    private:
        std::size_t _width;
        std::size_t _height;

        std::unordered_map<std::string, std::unique_ptr<IDisplay>> _displays;
        std::string _currentDisplay;

        Camera3D _camera;
};

#endif /*SIMULATION_HPP_*/
