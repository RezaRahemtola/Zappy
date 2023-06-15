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

void emit_egg_laying_event(size_t player_id, server_t *server)
{
    size_t len = snprintf(NULL, 0, "pfk %ld\n", player_id) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "pfk %ld\n", player_id);
    send_event(server->clients, content, true);
}
