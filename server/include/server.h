/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** server
*/

#pragma once

#include "parameters.h"
#include "network.h"
#include "my_list.h"

typedef struct client_s {
    socket_t socket;
} client_t;

typedef struct server_s {
    socket_t *socket;
    list_t *clients;
} server_t;

void launch_server(params_t *params);
