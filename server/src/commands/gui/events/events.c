/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** events
*/

#include <string.h>
#include <malloc.h>
#include "types.h"
#include "parameters.h"

void send_event(list_t *clients, char *message, bool free_msg)
{
    client_t *client = NULL;

    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->team != NULL
        && strcmp(client->team->name, GUI_TEAM_NAME) == 0)
            list_add(&client->output_messages, strdup(message));
    }
    if (free_msg)
        free(message);
}
