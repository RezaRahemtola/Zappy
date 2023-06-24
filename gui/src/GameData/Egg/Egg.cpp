/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Egg.cpp
*/

#include "Egg.hpp"

void Egg::display() {
    if (_size >= 1.5)
        _tendency = false;
    else if (_size <= 0.5)
        _tendency = true;

    if (_tendency)
        _size += 0.02;
    else
        _size -= 0.02;

    DrawCube(_position, _size, _size, _size, WHITE);
}
