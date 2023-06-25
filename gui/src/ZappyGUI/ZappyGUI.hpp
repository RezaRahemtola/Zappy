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

enum class Views {
    FREE,
    TOP,
};

class ZappyGUI {
    public:
        ZappyGUI(std::string machine, std::size_t port) : _width(1920), _height(1080), _playground(Playground(machine, port)) {
            InitWindow(_width, _height, "The ZOATIEST Project");
            _view = Views::FREE;

            SetTargetFPS(120);
            _camera.position = { 20.0f, 50.0f, 21.0f };
            _camera.target = { 20.0f, 0.0f, 20.0f };
            _camera.up = { 0.0f, 3.0f, 0.0f };
            _camera.fovy = 60.0f;
            _camera.projection = CAMERA_PERSPECTIVE;
        }
        ~ZappyGUI() {
            CloseWindow();
        };

        void run();

    private:
        // Window
        std::size_t _width;
        std::size_t _height;

        // Content
        Playground _playground;

        std::unordered_map<Ressource, int> _ressources;

        // Graphical elements
        Camera3D _camera;
        Views _view;
        Ray _ray;

        void handleCamera();
        void display3D();
        void display2D();

        void displayFPS();

        void displayTopInfos();
        void displayFreeInfos();
};

#endif /*SIMULATION_HPP_*/
