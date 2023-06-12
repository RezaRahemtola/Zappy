/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** game player
*/

#pragma once

#include "types.h"

game_t *create_game(params_t *params);
void destroy_game(game_t *game, params_t *params);

// Game
void eat_food(server_t *server);
