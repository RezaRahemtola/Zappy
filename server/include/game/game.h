/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** game player
*/

#pragma once

#include "types.h"

#define WIN_NEEDED_PLAYERS 6
#define WIN_NEEDED_LEVEL 8

game_t *create_game(params_t *params);
void destroy_game(game_t *game, params_t *params);

// Game
void game_logic(server_t *server, bool (*running)(bool val));
bool check_endgame(server_t *server);
