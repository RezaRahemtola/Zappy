/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** map
*/

#include <malloc.h>
#include "game/map.h"
#include "game/player.h"

void destroy_map(tile_t ***map, size_t width, size_t height)
{
    if (map == NULL)
        return;
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++)
            free(map[i][j]);
        free(map[i]);
    }
    free(map);
}

tile_t *create_tile(void)
{
    tile_t *tile = malloc(sizeof(tile_t));

    if (tile == NULL)
        return NULL;
    tile->food = 0;
    tile->linemate = 0;
    tile->deraumere = 0;
    tile->sibur = 0;
    tile->mendiane = 0;
    tile->phiras = 0;
    tile->thystame = 0;
    return tile;
}

tile_t ***create_map(size_t width, size_t height)
{
    tile_t ***map = malloc(sizeof(tile_t **) * height);

    for (size_t i = 0; i < height; i++) {
        map[i] = malloc(sizeof(tile_t **) * width);
        for (size_t j = 0; j < width; j++) {
            map[i][j] = create_inventory(0);
        }
    }
    return map;
}
