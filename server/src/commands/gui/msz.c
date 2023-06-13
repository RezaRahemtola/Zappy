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

void msz(list_t *args, client_t *client, server_t *server, char **result)
{
    (void)args;
    (void)client;
    size_t width = server->params->width;
    size_t height = server->params->height;
    size_t len = snprintf(NULL, 0, "msz %ld %ld\n", width, height) + 1;

    *result = malloc(sizeof(char) * len);
    if (*result == NULL)
        return;
    sprintf(*result, "msz %ld %ld\n", width, height);
}
