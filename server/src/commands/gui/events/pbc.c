/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** pnw
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "parameters.h"
#include "types.h"

void emit_broadcast_event(const char *message, server_t *server, size_t id)
{
    list_t *clients = server->clients;
    client_t *client = NULL;
    size_t len = snprintf(NULL, 0, "pbc %ld %s\n", id, message) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "pbc %ld %s\n", id, message);
    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->team != NULL
        && strcmp(client->team->name, GUI_TEAM_NAME) == 0)
            list_add(&client->output_messages, strdup(content));
    }
    free(content);
}
