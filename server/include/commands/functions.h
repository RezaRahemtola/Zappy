/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** command functions
*/

#pragma once

#include "types.h"

#define UNKNOWN_COMMAND_GUI "suc\n"
#define UNKNOWN_COMMAND_AI "ko\n"
#define UNKNOWN_COMMAND_PARAMETER "sbp\n"

void msz(list_t *args, client_t *client, server_t *server, char **result);
void tna(list_t *args, client_t *client, server_t *server, char **result);
void sgt(list_t *args, client_t *client, server_t *server, char **result);
void sst(list_t *args, client_t *client, server_t *server, char **result);
void ppo(list_t *args, client_t *client, server_t *server, char **result);
void plv(list_t *args, client_t *client, server_t *server, char **result);

void connect_nbr(list_t *args, client_t *client, server_t *serv, char **);
