/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP_
	#define MENU_HPP_

    #include <iostream>
    #include <SFML/Graphics.hpp>
    #include "IDisplay.hpp"
    #include "Button.hpp"

class Menu : public IDisplay {
    public:
        Menu() {};
        ~Menu() override {};

        std::string run() override;
        void display() override;

    private:
};

#endif /*MENU_HPP_*/
