/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** command functions
*/

#pragma once

#include "types.h"

#define UNKNOWN_COMMAND "suc\n"
#define UNKNOWN_COMMAND_PARAMETER "sbp\n"

void msz(list_t *args, client_t *client, server_t *server, char **result);
void tna(list_t *args, client_t *client, server_t *server, char **result);
void sgt(list_t *args, client_t *client, server_t *server, char **result);
void sst(list_t *args, client_t *client, server_t *server, char **result);
