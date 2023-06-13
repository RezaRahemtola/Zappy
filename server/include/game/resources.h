/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** game player
*/

#pragma once

#include <stddef.h>

static const char *RESOURCES[] = {"food", "linemate", "deraumere",
                                "sibur", "mendiane", "phiras",
                                "thystame", NULL};

tile_t *spawn_ressource(tile_t ***map, size_t width, size_t height);
