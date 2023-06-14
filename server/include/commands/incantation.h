/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** command functions
*/

#pragma once

#include "types.h"

#define INCANT_DATA_SIZE 7

typedef struct incant_s {
    size_t players;
    size_t linemate;
    size_t deraumere;
    size_t sibur;
    size_t mendiane;
    size_t phiras;
    size_t thystame;
} incant_t;

static const incant_t INCANT_DATA[INCANT_DATA_SIZE] = {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1,1, 0, 0, 0},
    {2, 2, 0, 1, 0,2,0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
};

// Functions
void incant_end_func(list_t *args, client_t *, server_t *serv, char **result);
