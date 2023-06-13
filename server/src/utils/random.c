/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** random
*/

//#include <stddef.h>
#include <stdlib.h>

size_t rand_between_range(size_t lowest, size_t higher)
{
    size_t num = rand();

    return (num % (higher - lowest + 1)) + lowest;
}
