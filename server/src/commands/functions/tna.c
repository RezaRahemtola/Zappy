/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** msz
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "commands/functions.h"
#include "parameters.h"

void tna(list_t *args, client_t *client, server_t *server)
{
    (void)args;
    team_t *team = NULL;
    char *content = NULL;
    list_t *teams = server->params->teams;
    size_t len = 0;

    for (; teams != NULL; teams = teams->next) {
        team = teams->data;
        if (strcmp(team->name, GUI_TEAM_NAME) == 0)
            continue;
        len = snprintf(NULL, 0, "tna %s\n", team->name) + 1;
        content = malloc(sizeof(char) * len);
        if (content == NULL)
            continue;
        sprintf(content, "tna %s\n", team->name);
        list_add(&client->output_messages, content);
    }
}
