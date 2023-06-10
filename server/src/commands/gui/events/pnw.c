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

static char *get_content(client_t *client)
{
    char *result = NULL;
    player_t *pl = client->player;
    size_t len = snprintf(NULL, 0, "pnw #%ld %ld %ld %d %ld %s\n",
                        pl->id, pl->x, pl->y, pl->orientation,
                        pl->level, client->team) + 1;

    result = malloc(sizeof(char) * len);
    if (result == NULL)
        return NULL;
    sprintf(result, "pnw #%ld %ld %ld %d %ld %s\n",
            pl->id, pl->x, pl->y, pl->orientation,
            pl->level, client->team);
    return result;
}

void emit_new_player_event(client_t *client, server_t *server)
{
    list_t *clients = server->clients;
    client_t *current = NULL;
    char *content = get_content(client);

    if (content == NULL)
        return;
    while (clients != NULL) {
        current = clients->data;
        if (current->team != NULL && strcmp(current->team, GUI_TEAM_NAME) == 0)
            list_add(&current->output_messages, strdup(content));
        clients = clients->next;
    }
    free(content);
}
