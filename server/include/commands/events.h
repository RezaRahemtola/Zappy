/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** events
*/

#pragma once

#include "types.h"

enum RESOURCE_EVENT {
    TAKE,
    SET
};

void emit_new_player_event(client_t *client, server_t *server);
void emit_broadcast_event(const char *message, server_t *server, size_t id);
void emit_resource_event(enum RESOURCE_EVENT evt, const char *resource,
    server_t *server, size_t id);
void emit_egg_laying_event(size_t player_id, list_t *clients);
void emit_egg_layed_event(player_t *player, server_t *serv, team_t *team);
void emit_dead_egg_event(size_t id, list_t *clients);
void emit_connect_egg(size_t id, player_t *player, list_t *clients);
void emit_dead_player_event(client_t *client, server_t *server);
void emit_eject_player_event(client_t *client, server_t *server);
void emit_incant_start_event(player_t *pl, list_t *clients);
void emit_incant_end_event(size_t x, size_t y, bool success, list_t *clients);
void emit_endgame_event(const char *team, list_t *clients);

// Utils
void send_event(list_t *clients, char *message, bool free_msg);
