/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** ErrorHandling.cpp
*/

#include <iostream>

int errorHandling(int argc, char const **argv)
{
    int i = 0;

    // check number of arguments
    if (argc != 3 && argc != 5) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 84;
    }

    // check if port number is valid
    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "-p") {
            if (!argv[i + 1] || std::stoi(argv[i + 1]) < 0 || std::stoi(argv[i + 1]) > 65535) {
                std::cerr << "Error: Invalid port number" << std::endl;
                return 84;
            }
        }
    }

    // check if -p is present
    for (i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "-p")
            continue;
    }
    if (i == argc) {
        std::cerr << "Error: Port number is mandatory" << std::endl;
        return 84;
    }
    return 0;
}
