/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Button.cpp
*/

#include <iostream>
#include "Button.hpp"

bool Button::isClicked() {
    if (_state == STATE::CLICKED) {
        _state = STATE::IDLE;
        return true;
    }
    return false;
}

void Button::handleState() {

}

void Button::display() {

}
