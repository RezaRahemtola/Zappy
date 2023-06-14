/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** commands list
*/

#pragma once

#include <stddef.h>
#include "../types.h"
#include "functions.h"

void base_end_func(list_t *args, client_t *client, server_t *server,
                    char **result);

static command_t GUI_COMMANDS[] = {
    {"msz", msz, base_end_func, NULL, NULL, 0, {0}},
    {"tna", tna, base_end_func, NULL, NULL, 0, {0}},
    {"sgt", sgt, base_end_func, NULL, NULL, 0, {0}},
    {"sst", sst, base_end_func, NULL, NULL, 0, {0}},
    {"ppo", ppo, base_end_func, NULL, NULL, 0, {0}},
    {"plv", plv, base_end_func, NULL, NULL, 0, {0}},
    {"pin", pin, base_end_func, NULL, NULL, 0, {0}},
    {"bct", bct, base_end_func, NULL, NULL, 0, {0}},
    {"mct", mct, base_end_func, NULL, NULL, 0, {0}},
    {NULL, NULL, base_end_func, NULL, NULL, 0, {0}}
};

static command_t AI_COMMANDS[] = {
    {"Connect_nbr", connect_nbr, base_end_func, NULL, NULL, 0, {0}},
    {"Inventory", inventory, base_end_func, NULL, NULL, 1, {0}},
    {"Right", right, base_end_func, NULL, NULL, 7, {0}},
    {"Left", left, base_end_func, NULL, NULL, 7, {0}},
    {"Forward", forward, base_end_func, NULL, NULL, 7, {0}},
    {"Broadcast", broadcast, base_end_func, NULL, NULL, 7, {0}},
    {"Take", take_obj, base_end_func, NULL, NULL, 7, {0}},
    {"Set", set_obj, base_end_func, NULL, NULL, 7, {0}},
    {"Fork", fork_player, base_end_func, NULL, NULL, 42, {0}},
    {"Look", look, base_end_func, NULL, NULL, 7, {0}},
    {"Eject", eject, base_end_func, NULL, NULL, 7, {0}},
    {NULL, NULL, base_end_func, NULL, NULL, 0, {0}}
};
