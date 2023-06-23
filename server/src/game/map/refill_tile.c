/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** refill_tile
*/

#include "game/map.h"
#include "utils.h"

bool is_tile_empty(tile_t *tile)
{
    if (!tile->food && !tile->linemate && !tile->deraumere && !tile->sibur
    && !tile->mendiane && !tile->thystame && !tile->phiras) {
        return true;
    }
    return false;
}

bool is_resource_still_avaible(tile_t *new_resources, size_t rand_res)
{
    if (rand_res == 0 && new_resources->food != 0)
        return true;
    if (rand_res == 1 && new_resources->linemate != 0)
        return true;
    if (rand_res == 2 && new_resources->deraumere != 0)
        return true;
    if (rand_res == 3 && new_resources->sibur != 0)
        return true;
    if (rand_res == 4 && new_resources->mendiane != 0)
        return true;
    if (rand_res == 5 && new_resources->phiras != 0)
        return true;
    if (rand_res == 6 && new_resources->thystame != 0)
        return true;
    return false;
}

tile_t *remove_resource(tile_t *tile, size_t resource)
{
    if (resource == 0)
        tile->food -= 1;
    if (resource == 1)
        tile->linemate -= 1;
    if (resource == 2)
        tile->deraumere -= 1;
    if (resource == 3)
        tile->sibur -= 1;
    if (resource == 4)
        tile->mendiane -= 1;
    if (resource == 5)
        tile->phiras -= 1;
    if (resource == 6)
        tile->thystame -= 1;
    return tile;
}

tile_t *add_resource(tile_t *tile, size_t resource)
{
    if (resource == 0)
        tile->food += 1;
    if (resource == 1)
        tile->linemate += 1;
    if (resource == 2)
        tile->deraumere += 1;
    if (resource == 3)
        tile->sibur += 1;
    if (resource == 4)
        tile->mendiane += 1;
    if (resource == 5)
        tile->phiras += 1;
    if (resource == 6)
        tile->thystame += 1;
    return tile;
}

tile_t *fill_tile(tile_t *map, tile_t *new_resources, bool only_empty)
{
    bool fill = false;
    size_t rand_res = 0;

    if (only_empty && !is_tile_empty(map))
        return map;
    while (!fill) {
        rand_res = rand_between_range(0, 7);
        fill = is_resource_still_avaible(new_resources, rand_res);
    }
    add_resource(map, rand_res);
    remove_resource(new_resources, rand_res);
    return map;
}
