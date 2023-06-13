/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** sgt
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "commands/functions.h"

void sgt(list_t *args, client_t *client, server_t *server, char **result)
{
    (void)args;
    (void)client;
    size_t freq = server->params->freq;
    size_t len = snprintf(NULL, 0, "sgt %ld\n", freq) + 1;

    *result = malloc(sizeof(char) * len);
    if (*result == NULL)
        return;
    sprintf(*result, "sgt %ld\n", freq);
}
