/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** connect_nbr
*/

#include <stdio.h>
#include <malloc.h>
#include "utils.h"
#include "commands/functions.h"

void connect_nbr(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    team_t *team = get_team_by_name(client->team, serv->params->teams);
    size_t len = 0;

    if (team == NULL)
        return;
    len = snprintf(NULL, 0, "%ld\n", team->clientsNb) + 1;

    *result = malloc(sizeof(char) * len);
    if (*result == NULL)
        return;
    sprintf(*result, "%ld\n", team->clientsNb);
}
