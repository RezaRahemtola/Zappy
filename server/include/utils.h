/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** utils
*/

#pragma once

#include "parameters.h"

team_t *get_team_by_name(const char *name, list_t *teams);
player_t *get_player_by_id(list_t *clients, size_t id);
bool add_elem_to_tile(tile_t ***map, player_t *player, const char *e, int nb);
