/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** network
*/

#pragma once

#include "../types.h"

#define MESSAGE_KO "ko\n"

void read_message(client_t *client, server_t *server);

// Parsing
list_t *split_message(char *message);
