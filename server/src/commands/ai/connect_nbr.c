/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** connect_nbr
*/

#include <stdio.h>
#include <malloc.h>
#include "commands/functions.h"

void connect_nbr(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    (void)serv;
    size_t clientsNb = 0;
    size_t len = 0;

    if (client->team == NULL)
        return;
    clientsNb = list_size(client->team->eggs);
    len = snprintf(NULL, 0, "%ld\n", clientsNb) + 1;
    *result = malloc(sizeof(char) * len);
    if (*result == NULL)
        return;
    sprintf(*result, "%ld\n", clientsNb);
}
