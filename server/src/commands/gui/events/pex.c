/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** pex
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "commands/events.h"

void emit_eject_player_event(client_t *client, server_t *server)
{
    size_t len = snprintf(NULL, 0, "pex %ld\n", client->player->id);
    char *content = malloc(sizeof(char) * (len + 1));

    if (content == NULL)
        return;
    sprintf(content, "pex %ld\n", client->player->id);
    send_event(server->clients, content, true);
}
