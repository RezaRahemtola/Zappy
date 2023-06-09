/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** commands
*/

#pragma once

#include "types.h"

#define MAX_COMMANDS_PER_CLIENT 10

void handle_command(list_t *args, client_t *client, server_t *server);
void destroy_command(command_t *command);

// Execution
void execute_commands(server_t *server);
