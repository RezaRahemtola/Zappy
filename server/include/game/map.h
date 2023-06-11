/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** game player
*/

#pragma once

#include "types.h"

tile_t ***create_map(size_t width, size_t height);
void destroy_map(tile_t ***map, size_t width, size_t height);
