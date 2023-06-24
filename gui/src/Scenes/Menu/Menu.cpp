/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Menu.cpp
*/

#include <iostream>
#include "Menu.hpp"

std::string Menu::run() {
    display();
    if (IsKeyPressed(KEY_ENTER))
        return "Playground";
    if (IsKeyPressed(KEY_ESCAPE))
        return "Exit";
    return "Menu";
}

void Menu::display() {
}
