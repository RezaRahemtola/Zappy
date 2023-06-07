/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** Utils.hpp
*/
#ifndef UTILS_HPP_
	#define UTILS_HPP_

    #define DEFAULT_MACHINE "localhost"

int errorHandling(int argc, char const **argv);
int help();

std::string getMachine(int argc, char const **argv);
std::size_t getPort(int argc, char const **argv);

#endif /*UTILS_HPP_*/