/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** game player
*/

#pragma once

#include "types.h"

#define BASE_PLAYER_FOOD 10

void destroy_player(player_t *player);

void init_player(client_t *client, server_t *server);
