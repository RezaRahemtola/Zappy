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

void emit_egg_laying_event(size_t player_id, server_t *server)
{
    size_t len = snprintf(NULL, 0, "pfk %ld\n", player_id) + 1;
    char *content = malloc(sizeof(char) * len);
    char *message = NULL;
    list_t *clients = server->clients;
    client_t *client = NULL;

    if (content == NULL)
        return;
    sprintf(content, "pfk %ld\n", player_id);
    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        message = strdup(content);
        if (message == NULL)
            continue;
        if (client->team != NULL
        && strcmp(client->team->name, GUI_TEAM_NAME) == 0)
            list_add(&client->output_messages, message);
    }
    free(content);
}
