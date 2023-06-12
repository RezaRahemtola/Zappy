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

void emit_dead_player_event(client_t *client, server_t *server)
{
    size_t len = snprintf(NULL, 0, "pdi %ld\n", client->player->id);
    char *content = malloc(sizeof(char) * (len + 1));
    list_t *clients = server->clients;
    client_t *current = NULL;

    if (content == NULL)
        return;
    sprintf(content, "pdi %ld\n", client->player->id);
    for (; clients != NULL; clients = clients->next) {
        current = clients->data;
        if (current->team != NULL
        && strcmp(current->team->name, GUI_TEAM_NAME) == 0)
            list_add(&current->output_messages, strdup(content));

    }
    free(content);
}
