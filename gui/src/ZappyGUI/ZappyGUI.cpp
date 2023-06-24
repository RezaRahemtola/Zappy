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

        // 3D mode
        BeginMode3D(_camera);
        _displays[_currentDisplay]->display();
        DrawGrid(200, 1.0f);
        EndMode3D();

        // Camera Handler
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

        // Camera movement controled by keyboard relative to camera facing
        UpdateCameraPro(&_camera,
                        (Vector3){
                            (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))*0.1f - (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))*0.1f,
                            (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))*0.1f - (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))*0.1f,
                            (IsKeyDown(KEY_E) || IsKeyDown(KEY_SPACE))*0.1f - (IsKeyDown(KEY_Q) || IsKeyDown(KEY_LEFT_SHIFT))*0.1f
                        },
                        (Vector3){0.0f, 0.0f, 0.0f},
                        GetMouseWheelMove()*2.0f);

        // 2D mode
        DrawRectangle(0, 0, 110, 40, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(0, 0, 110, 40, Fade(DARKBLUE, 0.5f));
        DrawText("Welcome to the Zappy Of All Time", _width / 2 - 270, 10, 30, GRAY);

        DrawText("Press [ESC] to exit", _width - 200, _height - 80, 20, GRAY);

        DrawFPS(10, 10);
        EndDrawing();
    }
}
