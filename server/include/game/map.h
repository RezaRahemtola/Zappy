/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** game player
*/

#pragma once

#include "types.h"

#define RESOURCE_GENERATION_DURATION 20

tile_t ***create_map(size_t width, size_t height);
void destroy_map(tile_t ***map, size_t width, size_t height);

// Map refill
tile_t ***fill_map(tile_t ***map, size_t width, size_t height);
tile_t *fill_tile(tile_t *map, tile_t *new_resources, bool only_empty);
bool is_tile_empty(tile_t *tile);
tile_t *spawn_resource(tile_t ***map, size_t width, size_t height);
