/*
** EPITECH PROJECT, 2023
** PrivateZappy
** File description:
** new_resources
*/

#include <stddef.h>
#include "game/map.h"
#include "game/player.h"

tile_t *max_resources_on_map(size_t width, size_t height)
{
    tile_t *tile = create_inventory(0);

    if (tile == NULL)
        return tile;
    tile->food = width * height * 0.5;
    tile->linemate = width * height * 0.3;
    tile->deraumere = width * height * 0.15;
    tile->sibur = width * height * 0.1;
    tile->mendiane = width * height * 0.1;
    tile->phiras = width * height * 0.08;
    tile->thystame = width * height * 0.05;
    return tile;
}

tile_t *spawn_resource(tile_t ***map, size_t width, size_t height)
{
    tile_t *tile = max_resources_on_map(width, height);

    if (tile == NULL)
        return tile;
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            tile->food -= (tile->food == 0) ? 0 : map[i][j]->food;
            tile->linemate -= (tile->linemate == 0) ? 0 : map[i][j]->linemate;
            tile->deraumere -= (tile->deraumere == 0) ? 0
                    : map[i][j]->deraumere;
            tile->sibur -= (tile->sibur == 0) ? 0 : map[i][j]->sibur;
            tile->mendiane -= (tile->mendiane == 0) ? 0 : map[i][j]->mendiane;
            tile->phiras -= (tile->phiras == 0) ? 0 : map[i][j]->phiras;
            tile->thystame -= (tile->thystame == 0) ? 0 : map[i][j]->thystame;
        }
    }
    return tile;
}
