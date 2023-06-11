/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** resource events
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "commands/functions.h"
#include "parameters.h"
#include "game/resources.h"

static short get_resource_nb(const char *resource)
{
    for (short i = 0; RESOURCES[i] != NULL; i++)
        if (strcmp(resource, RESOURCES[i]) == 0)
            return i;
    return 0;
}

void emit_drop_resource_event(const char *resource, server_t *server, size_t id)
{
    list_t *clients = server->clients;
    client_t *client = NULL;
    short nb = get_resource_nb(resource);
    size_t len = snprintf(NULL, 0, "pdr %ld %d\n", id, nb) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "pdr %ld %d\n", id, nb);
    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->team != NULL && strcmp(client->team, GUI_TEAM_NAME) == 0)
            list_add(&client->output_messages, strdup(content));
    }
    free(content);
}
