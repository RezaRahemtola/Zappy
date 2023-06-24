/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** IDisplay.hpp
*/

#ifndef IDISPLAY_HPP_
	#define IDISPLAY_HPP_

    #include <SFML/Graphics.hpp>

class IDisplay {
    public:
        virtual ~IDisplay() = default;

        virtual std::string run() = 0;
        virtual void display() = 0;
};

#endif /*IDISPLAY_HPP_*/
