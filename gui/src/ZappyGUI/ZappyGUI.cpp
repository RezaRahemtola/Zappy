/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ZappyGUI.cpp
*/

#include <iostream>
#include "ZappyGUI.hpp"

void ZappyGUI::run() {
    while (!WindowShouldClose()) {
        _playground.run();
        _ray = GetMouseRay(GetMousePosition(), _camera);

        if (_view == Views::TOP)
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                _ressources = _playground.getRessources(_ray);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        display3D();
        handleCamera();

        // 2D mode
        display2D();
        EndDrawing();
    }
}

// 2D mode
void ZappyGUI::display2D() {
    if (_view == Views::TOP) {
        DrawText("Welcome to the Zappy Of All Time", _width / 2 - 500, 10, 30, GRAY);
        DrawText("Press [ESC] to exit", _width / 2 - 200, _height - 80, 20, GRAY);
        displayTopInfos();
    } else {
        DrawText("Welcome to the Zappy Of All Time", _width / 2 - 270, 10, 30, GRAY);
        DrawText("Press [ESC] to exit", _width - 200, _height - 80, 20, GRAY);
        displayFreeInfos();
    }

    displayFPS();
}

void ZappyGUI::displayTopInfos() {
    DrawRectangle(3 * _width / 4, 0, 3 * _width / 4, _height, Fade(GRAY, 0.7f));
    DrawRectangleLines(3 * _width / 4, 0, 3 * _width / 4, _height, Fade(DARKGRAY, 0.8f));
    std::cout << "Display Top Infos" << std::endl;

    // Display ressources
    DrawText("Ressources", 3 * _width / 4 + 10, 10, 20, DARKGRAY);

    DrawText(("Food: " + std::to_string(_ressources[Ressource::FOOD])).c_str(), 3 * _width / 4 + 10, 40, 20, DARKGRAY);
    DrawRectangle(3 * _width / 4 + 50, 70, 100, 100, Fade(BEIGE, 0.5f));
    DrawRectangleLines(3 * _width / 4 + 50, 70, 100, 100, Fade(BLACK, 0.5f));

    DrawText(("Linemate: " + std::to_string(_ressources[Ressource::LINEMATE])).c_str(), 3 * _width / 4 + 10, 180, 20, DARKGRAY);
    DrawRectangle(3 * _width / 4 + 50, 210, 100, 100, Fade(LIGHTGRAY, 0.5f));
    DrawRectangleLines(3 * _width / 4 + 50, 210, 100, 100, Fade(BLACK, 0.5f));

    DrawText(("Deraumere: " + std::to_string(_ressources[Ressource::DERAUMERE])).c_str(), 3 * _width / 4 + 10, 320, 20, DARKGRAY);
    DrawRectangle(3 * _width / 4 + 50, 350, 100, 100, Fade(YELLOW, 0.5f));
    DrawRectangleLines(3 * _width / 4 + 50, 350, 100, 100, Fade(BLACK, 0.5f));

    DrawText(("Sibur: " + std::to_string(_ressources[Ressource::SIBUR])).c_str(), 3 * _width / 4 + 10, 460, 20, DARKGRAY);
    DrawRectangle(3 * _width / 4 + 50, 490, 100, 100, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(3 * _width / 4 + 50, 490, 100, 100, Fade(BLACK, 0.5f));

    DrawText(("Mendiane: " + std::to_string(_ressources[Ressource::MENDIANE])).c_str(), 3 * _width / 4 + 10, 600, 20, DARKGRAY);
    DrawRectangle(3 * _width / 4 + 50, 630, 100, 100, Fade(PURPLE, 0.5f));
    DrawRectangleLines(3 * _width / 4 + 50, 630, 100, 100, Fade(BLACK, 0.5f));

    DrawText(("Phiras: " + std::to_string(_ressources[Ressource::PHIRAS])).c_str(), 3 * _width / 4 + 10, 740, 20, DARKGRAY);
    DrawRectangle( 3 * _width / 4 + 50, 770, 100, 100, Fade(ORANGE, 0.5f));
    DrawRectangleLines(3 * _width / 4 + 50, 770, 100, 100, Fade(BLACK, 0.5f));

    DrawText(("Thystame: " + std::to_string(_ressources[Ressource::THYSTAME])).c_str(), 3 * _width / 4 + 10, 880, 20, DARKGRAY);
    DrawRectangle(3 * _width / 4 + 50, 910, 100, 100, Fade(PINK, 0.5f));
    DrawRectangleLines(3 * _width / 4 + 50, 910, 100, 100, Fade(BLACK, 0.5f));

}

void ZappyGUI::displayFreeInfos() {

}

// Display FPS
void ZappyGUI::displayFPS() {
    DrawRectangle(0, 0, 110, 40, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(0, 0, 110, 40, Fade(DARKBLUE, 0.5f));
    DrawFPS(10, 10);
}

// 3D mode
void ZappyGUI::display3D() {
    BeginMode3D(_camera);
    _playground.display();
    DrawGrid(500, 1.0f);
    EndMode3D();
}

// Camera movement controled by keyboard relative to camera facing
void ZappyGUI::handleCamera() {
    // Set view by command
    if (IsKeyDown(KEY_F)) {
        _view = Views::FREE;
    }
    if (IsKeyDown(KEY_T)) {
        _view = Views::TOP;
        if (IsCursorHidden()) {
            EnableCursor();
        }
    }

    // Handle camera movement
    if (_view == Views::FREE) {
        // Handle camera rotation by mouse
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            if (IsCursorHidden()) {
                EnableCursor();
            }
            else {
                DisableCursor();
            }
        }

        if (IsCursorHidden()) {
            UpdateCamera(&_camera, CAMERA_FIRST_PERSON);
        }

        // Update camera
        UpdateCameraPro(&_camera,
                        (Vector3) {
                            (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) * 0.2f -
                            (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) * 0.2f,
                            (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) * 0.2f -
                            (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) * 0.2f,
                            (IsKeyDown(KEY_E) || IsKeyDown(KEY_SPACE)) * 0.2f -
                            (IsKeyDown(KEY_Q) || IsKeyDown(KEY_LEFT_SHIFT)) * 0.2f
                        },
                        (Vector3) {0.0f, 0.0f, 0.0f},
                        GetMouseWheelMove() * 2.0f);
    } else {
        _camera.position = { 30.0f, 45.0f, 21.0f };
        _camera.target = {30.0f, 0.0f, 20.0f };
        _camera.up = { 0.0f, 3.0f, 0.0f };
        _camera.fovy = 60.0f;
        _camera.projection = CAMERA_PERSPECTIVE;
    }
}
