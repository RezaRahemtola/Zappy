/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** direction utils
*/

#include "types.h"

size_t get_x(size_t x, size_t max, mov_t *mov, size_t offset)
{
    if ((mov->orientation == 1 && mov->dir == LEFT)
        || (mov->orientation == 2 && mov->dir == BACK)
        || (mov->orientation == 3 && mov->dir == RIGHT)
        || (mov->orientation == 4 && mov->dir == FRONT))
        return ((int)x - (int)offset) >= 0 ? (x - offset) : (max - x - offset);
    if ((mov->orientation == 1 && mov->dir == RIGHT)
        || (mov->orientation == 2 && mov->dir == FRONT)
        || (mov->orientation == 3 && mov->dir == LEFT)
        || (mov->orientation == 4 && mov->dir == BACK))
        return (x + offset) < max ? (x + offset) : (x + offset - max);
    if ((mov->orientation == 1 && (mov->dir == FRONT || mov->dir == BACK))
        || (mov->orientation == 2 && (mov->dir == LEFT || mov->dir == RIGHT))
        || (mov->orientation == 3 && (mov->dir == FRONT || mov->dir == BACK))
        || (mov->orientation == 4 && (mov->dir == LEFT || mov->dir == BACK)))
        return x;
    return 0;
}

size_t get_y(size_t y, size_t max, mov_t *mov, size_t offset)
{
    if ((mov->orientation == 1 && mov->dir == FRONT)
        || (mov->orientation == 2 && mov->dir == LEFT)
        || (mov->orientation == 3 && mov->dir == BACK)
        || (mov->orientation == 4 && mov->dir == RIGHT))
        return ((int)y - (int)offset) >= 0 ? (y - offset) : (max - y - offset);
    if ((mov->orientation == 1 && mov->dir == BACK)
        || (mov->orientation == 2 && mov->dir == RIGHT)
        || (mov->orientation == 3 && mov->dir == FRONT)
        || (mov->orientation == 4 && mov->dir == LEFT))
        return (y + offset) < max ? (y + offset) : (y + offset - max);
    if ((mov->orientation == 1 && (mov->dir == LEFT || mov->dir == RIGHT))
        || (mov->orientation == 2 && (mov->dir == BACK || mov->dir == FRONT))
        || (mov->orientation == 3 && (mov->dir == LEFT || mov->dir == RIGHT))
        || (mov->orientation == 4 && (mov->dir == BACK || mov->dir == FRONT)))
        return y;
    return 0;
}
