/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** game player
*/

#pragma once

#include "types.h"

#define BASE_PLAYER_FOOD 10
#define FOOD_DURATION 126
#define AI_DEAD "dead\n"

void destroy_player(player_t *player);
void init_player(client_t *client, server_t *server);

// Inventory
inventory_t *create_inventory(size_t base_food);
