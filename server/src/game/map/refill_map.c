/*
** EPITECH PROJECT, 2023
** PrivateZappy
** File description:
** update_map
*/

#include <stdlib.h>

#include "game/map.h"
#include "utils.h"

tile_t ***fill_empty_map(tile_t ***map, size_t width, size_t height)
{
    tile_t *new_resources = spawn_resource(map, width, height);

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

tile_t ***refill_map(tile_t ***map, size_t width, size_t height)
{
    tile_t *new_resources = NULL;
    size_t x = 0;
    size_t y = 0;

    map = fill_empty_map(map, width, height);
    new_resources = spawn_resource(map, width, height);
    if (new_resources == NULL)
        return map;
    while (!is_tile_empty(new_resources)) {
        x = rand_between_range(1, height) - 1;
        y = rand_between_range(1, width) - 1;
        map[x][y] = fill_tile(map[x][y], new_resources, false);
    }
    free(new_resources);
    return map;
}
