/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** GetArgs.cpp
*/

#include <iostream>
#include "Utils.hpp"

std::string getMachine(int argc, char const **argv)
{
    std::string machine = DEFAULT_MACHINE;

    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "-h" && i + 1 < argc)
            machine = std::string(argv[i + 1]);
    }
    return machine;
}

std::size_t getPort(int argc, char const **argv)
{
    std::size_t port = 0;

    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "-p" && i + 1 < argc)
            port = std::stoi(argv[i + 1]);
    }
    return port;
}
