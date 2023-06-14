/*
** EPITECH PROJECT, 2023
** PrivateZappy
** File description:
** update_map
*/

#include <stdlib.h>

#include "game/map.h"
#include "utils.h"

tile_t ***refill_empty_tile(tile_t ***map, size_t width, size_t height)
{
    tile_t *new_resources = spawn_ressource(map, width, height);

    if (new_resources == NULL)
        return map;
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            map[i][j] = fill_tile(map[i][j], new_resources, true);
        }
    }
    free(new_resources);
    return map;
}

tile_t ***fill_map(tile_t ***map, size_t width, size_t height)
{
    tile_t *new_resources = NULL;
    size_t x = 0;
    size_t y = 0;

    map = refill_empty_tile(map, width, height);
    new_resources = spawn_ressource(map, width, height);
    if (new_resources == NULL)
        return map;
    while (!is_tile_empty(new_resources)) {
        x = rand_between_range(1, height);
        y = rand_between_range(1, width);
        map[x - 1][y - 1] = fill_tile(map[x - 1][y - 1], new_resources, false);
    }
    free(new_resources);
    return map;
}
