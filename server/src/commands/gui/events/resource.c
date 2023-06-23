/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** resource events
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "commands/events.h"
#include "game/resources.h"

static short get_resource_nb(const char *resource)
{
    for (short i = 0; RESOURCES[i] != NULL; i++)
        if (strcmp(resource, RESOURCES[i]) == 0)
            return i;
    return 0;
}

void emit_resource_event(enum RESOURCE_EVENT evt, const char *resource,
    server_t *server, size_t id)
{
    char *name = (evt == TAKE) ? "pgt" : "pdr";
    short nb = get_resource_nb(resource);
    size_t len = snprintf(NULL, 0, "%s %ld %d\n", name, id, nb) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "%s %ld %d\n", name, id, nb);
    send_event(server->clients, content, true);
}
