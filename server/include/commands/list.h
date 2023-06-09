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
    {NULL, NULL, NULL, NULL, 0, 0}
};

static command_t AI_COMMANDS[] = {
    {"Connect_nbr", connect_nbr, NULL, NULL, 0, 0},
    {NULL, NULL, NULL, NULL, 0, 0}
};
