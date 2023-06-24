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

static char *get_team_names(list_t *teams)
{
    char *result = NULL;
    team_t *team = NULL;
    char *tmp = NULL;

    for (; teams != NULL; teams = teams->next) {
        team = teams->data;
        if (strcmp(team->name, GUI_TEAM_NAME) == 0)
            continue;
        if (result == NULL) {
            result = malloc(sizeof(char) * (strlen(team->name) + 2));
            sprintf(result, " %s", team->name);
        } else {
            tmp = malloc(sizeof(char) *
                    (snprintf(NULL, 0, "%s %s", result, team->name) + 1));
            sprintf(tmp, "%s %s", result, team->name);
            free(result);
            result = tmp;
        }
    }
    return result;
}

void tna(list_t *args, client_t *client, server_t *server, char **result)
{
    (void)args;
    (void)client;
    char *names = get_team_names(server->params->teams);
    size_t len = snprintf(NULL, 0, "tna%s\n", names) + 1;

    *result = malloc(sizeof(char) * len);
    sprintf(*result, "tna%s\n", names);
    free(names);
}
