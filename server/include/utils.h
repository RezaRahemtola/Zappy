/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** utils
*/

#pragma once

#include "parameters.h"

// Teams
team_t *get_team_by_name(const char *name, list_t *teams);

// Player
player_t *get_player_by_id(list_t *clients, size_t id);

// Tiles
bool add_elem_to_tile(tile_t ***map, player_t *player, const char *e, int nb);
char *get_tile_content(size_t x, size_t y, player_t *player, tile_t ***map);

// Direction
size_t get_x(size_t x, size_t max, mov_t *mov, size_t offset);
size_t get_y(size_t y, size_t max, mov_t *mov, size_t offset);

// Strings
char *new_strcat(char *str1, char *str2, bool free1, bool free2);

// Time
bool check_time(timeval_t start, size_t time, size_t freq);

// Random function
size_t rand_between_range(size_t lowest, size_t higher);
