/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** pnw
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "commands/events.h"

void emit_new_player_event(client_t *client, server_t *server)
{
    char *content = NULL;
    player_t *pl = client->player;
    size_t len = snprintf(NULL, 0, "pnw #%ld %ld %ld %d %ld %s\n",
                        pl->id, pl->x, pl->y, pl->orientation,
                        pl->level, client->team->name) + 1;

    content = malloc(sizeof(char) * len);
    if (content == NULL)
        return;
    sprintf(content, "pnw #%ld %ld %ld %d %ld %s\n",
            pl->id, pl->x, pl->y, pl->orientation,
            pl->level, client->team->name);
    send_event(server->clients, content, true);
}
