/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** time utils
*/

#include <stddef.h>
#include "types.h"

bool check_time(timeval_t start, size_t time, size_t freq)
{
    timeval_t end;
    size_t mult = 1000000;
    uint64_t diff = 0;
    uint64_t timer = 0;

    gettimeofday(&end, NULL);
    diff = (end.tv_sec - start.tv_sec) * mult + (end.tv_usec - start.tv_usec);
    timer = ((float)time / (float)freq) * mult;
    return diff >= timer;
}
