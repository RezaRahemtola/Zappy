//
// Created by Tomi-Tom on 3/28/23.
//

#include <iostream>
#include "Button.hpp"

bool Button::isClicked() {
    if (_state == STATE::CLICKED) {
        _state = STATE::IDLE;
        return true;
    }
    return false;
}

void Button::handleState(sf::RenderWindow &window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (mousePosition.x > _position.x && mousePosition.x < _position.x + _size.x &&
        mousePosition.y > _position.y && mousePosition.y < _position.y + _size.y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            _state = STATE::CLICKED;
        } else {
            _state = STATE::HOVER;
        }
    } else {
        _state = STATE::IDLE;
    }
}

void Button::display(sf::RenderWindow &window) {
    sf::Text text;
    sf::Vector2f textPosition = {_position.x + _size.x / 2 - ((_text.length() / 2) * 15) - (_text.length() % 2 ? 11 : 0) , _position.y + _size.y / 2 - 20};

    if (_state == STATE::IDLE) {
        _shape.setFillColor(_color);
        _shape.setPosition(_position);
        text.setPosition(textPosition);
    } else if (_state == STATE::HOVER) {
        _shape.setFillColor(sf::Color(_color.r - 25, _color.g - 25, _color.b - 25));
        _shape.setPosition(_position.x + 2, _position.y + 2);
        text.setPosition(textPosition.x + 2, textPosition.y + 2);
    } else if (_state == STATE::CLICKED) {
        _shape.setFillColor(sf::Color(_color.r - 50, _color.g - 50, _color.b - 50));
        _shape.setPosition(_position.x + 4, _position.y + 4);
        text.setPosition(textPosition.x + 4, textPosition.y + 4);
    }

    text.setFont(_font);
    text.setString(_text);
    text.setCharacterSize(32);
    text.setFillColor(sf::Color(63, 57, 68));
    handleState(window);

    window.draw(_shape);
    window.draw(text);
}
