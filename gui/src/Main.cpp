/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** main.cpp
*/

#include <iostream>
#include "Simulation.hpp"

int main(int argc, char const **argv, char const **env)
{
    srand(time(NULL));
    Simulation simulation;
    simulation.run();
    return 0;
}
