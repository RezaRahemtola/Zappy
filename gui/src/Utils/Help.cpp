/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** Help.cpp
*/

#include <iostream>

int help()
{
    std::cout << "USAGE: ./zappy_gui -p [PORT] -h [PORT]\n" << std::endl;
    std::cout << "\t[PORT]\t\tis the port number" << std::endl;
    std::cout << "\t[MACHINE]\tis the name of the machine; localhost by default" << std::endl;
    return 0;
}
