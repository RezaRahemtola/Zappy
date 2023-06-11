/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** command functions
*/

#pragma once

#include "types.h"

#define UNKNOWN_COMMAND_GUI "suc\n"
#define FAILED_COMMAND_AI "ko\n"
#define SUCCESS_COMMAND_AI "ok\n"
#define UNKNOWN_COMMAND_PARAMETER_GUI "sbp\n"

void msz(list_t *args, client_t *client, server_t *server, char **result);
void tna(list_t *args, client_t *client, server_t *server, char **result);
void sgt(list_t *args, client_t *client, server_t *server, char **result);
void sst(list_t *args, client_t *client, server_t *server, char **result);
void ppo(list_t *args, client_t *client, server_t *server, char **result);
void plv(list_t *args, client_t *client, server_t *server, char **result);
void pin(list_t *args, client_t *client, server_t *server, char **result);
void bct(list_t *args, client_t *client, server_t *server, char **result);
void mct(list_t *args, client_t *client, server_t *server, char **result);

void connect_nbr(list_t *args, client_t *client, server_t *serv, char **);
void inventory(list_t *args, client_t *client, server_t *serv, char **result);
void right(list_t *args, client_t *client, server_t *serv, char **result);
void left(list_t *args, client_t *client, server_t *serv, char **result);
void forward(list_t *args, client_t *client, server_t *serv, char **result);
void broadcast(list_t *args, client_t *client, server_t *serv, char **result);
void take_obj(list_t *args, client_t *client, server_t *serv, char **result);
void set_obj(list_t *args, client_t *client, server_t *serv, char **result);
void fork_player(list_t *args, client_t *client, server_t *serv, char **result);
