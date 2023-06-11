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

static command_t GUI_COMMANDS[] = {
    {"msz", msz, NULL, NULL, 0, 0},
    {"tna", tna, NULL, NULL, 0, 0},
    {"sgt", sgt, NULL, NULL, 0, 0},
    {"sst", sst, NULL, NULL, 0, 0},
    {"ppo", ppo, NULL, NULL, 0, 0},
    {"plv", plv, NULL, NULL, 0, 0},
    {"pin", pin, NULL, NULL, 0, 0},
    {NULL, NULL, NULL, NULL, 0, 0}
};

static command_t AI_COMMANDS[] = {
    {"Connect_nbr", connect_nbr, NULL, NULL, 0, 0},
    {"Inventory", inventory, NULL, NULL, 1, 0},
    {"Right", right, NULL, NULL, 7, 0},
    {"Left", left, NULL, NULL, 7, 0},
    {"Forward", forward, NULL, NULL, 7, 0},
    {"Broadcast", broadcast, NULL, NULL, 7, 0},
    {"Take", take_obj, NULL, NULL, 7, 0},
    {"Set", set_obj, NULL, NULL, 7, 0},
    {NULL, NULL, NULL, NULL, 0, 0}
};
