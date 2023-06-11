/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** events
*/

#pragma once

#include "../types.h"

void emit_new_player_event(client_t *client, server_t *server);
void emit_broadcast_event(const char *message, server_t *server, size_t id);
void emit_drop_resource_event(const char *resource, server_t *, size_t id);
