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
    srand(time(NULL));
    if (argc == 2 && std::string(argv[1]) == "-help") {
        return help();
    }
    if (errorHandling(argc, argv) == 84) {
        return 84;
    }

    ZappyGUI simulation(getMachine(argc, argv), getPort(argc, argv));
    std::cout << "Connecting to " << getMachine(argc, argv) << ":" << getPort(argc, argv) << std::endl;

    simulation.run();
    return 0;
}
