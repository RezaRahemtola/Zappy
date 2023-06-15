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

void emit_broadcast_event(const char *message, server_t *server, size_t id)
{
    size_t len = snprintf(NULL, 0, "pbc %ld %s\n", id, message) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "pbc %ld %s\n", id, message);
    send_event(server->clients, content, true);
}
