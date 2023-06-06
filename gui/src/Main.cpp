/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** main.cpp
*/

#include <iostream>
#include "ZappyGUI.hpp"
#include "Utils.hpp"

int main(int argc, char const **argv)
{
    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "-help")
            return help();
    }
    if (errorHandling(argc, argv) == 84)
        return 84;

    ZappyGUI simulation;

    srand(time(NULL));
    simulation.run();
    return 0;
}
