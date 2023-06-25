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
        _currentDisplay = _displays[_currentDisplay]->run();
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
        DrawText("Welcome to the Zappy Of All Time", _width / 2 - 750, 10, 30, GRAY);
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
    DrawRectangle(_width / 2, 0, _width / 2, _height, Fade(GRAY, 0.7f));
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
    _displays[_currentDisplay]->display();
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
        _camera.position = { 40.0f, 45.0f, 21.0f };
        _camera.target = { 40.0f, 0.0f, 20.0f };
        _camera.up = { 0.0f, 3.0f, 0.0f };
        _camera.fovy = 60.0f;
        _camera.projection = CAMERA_PERSPECTIVE;
    }
}
