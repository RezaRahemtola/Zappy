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

void msz(list_t *args, client_t *client, server_t *server)
{
    (void)args;
    char *content = NULL;
    size_t width = server->params->width;
    size_t height = server->params->height;
    size_t len = snprintf(NULL, 0, "msz %ld %ld\n", width, height) + 1;

    content = malloc(sizeof(char) * len);
    if (content == NULL)
        return;
    sprintf(content, "msz %ld %ld\n", width, height);
    list_add(&client->output_messages, content);
}
