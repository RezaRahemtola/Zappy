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

static command_t COMMANDS[] = {
    {"msz", msz, NULL, NULL, 0},
    {"tna", tna, NULL, NULL, 0},
    {"sgt", sgt, NULL, NULL, 0},
    {"sst", sst, NULL, NULL, 0},
    {NULL, NULL, NULL, NULL, 0}
};
