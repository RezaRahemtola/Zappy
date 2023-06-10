/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** broadcast
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "parameters.h"
#include "commands/functions.h"

static void send_message(server_t *serv, client_t *current, char *message)
{
    list_t *clients = serv->clients;
    client_t *client = NULL;
    short tile = 42;
    size_t len = snprintf(NULL, 0, "message %d, %s\n", tile, message) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "message %d, %s\n", tile, message);
    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (strcmp(client->team, GUI_TEAM_NAME) != 0
        && current->player->id != client->player->id)
            list_add(&client->output_messages, strdup(content));
    }
    free(content);
}

void broadcast(list_t *args, client_t *client, server_t *serv, char **result)
{
    list_t *text = args->next;
    const char *new = NULL;
    char *message = NULL;

    for (; text != NULL; text = text->next) {
        new = text->data;
        if (message == NULL) {
            message = malloc(sizeof(char) * (strlen(new) + 2));
            strcpy(message, new);
        } else {
            message = realloc(message, sizeof(char) *
            (strlen(message) + strlen(new) + 2));
            strcat(message, new);
        }
    }
    if (message != NULL)
        send_message(serv, client, message);
    free(message);
    *result = strdup(SUCCESS_COMMAND_AI);
}
