/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Button.hpp
*/

#ifndef BUTTON_HPP_
	#define BUTTON_HPP_

    #include <raylib.h>

enum class STATE {
    IDLE,
    HOVER,
    CLICKED
};

class Button {
    public:
        Button() = default;
        Button(std::string text, Vector2 position, Vector2 size) :
            _state(STATE::IDLE), _position(position), _size(size), _text(text) {
        };
        ~Button() {};

        bool isClicked();
        void display();

    private:
        STATE _state;
        Vector2 _position;
        Vector2 _size;
        std::string _text;

        void handleState();
};

#endif /*BUTTON_HPP_*/
