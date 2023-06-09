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

void sgt(list_t *args, client_t *client, server_t *server)
{
    (void)args;
    char *content = NULL;
    size_t freq = server->params->freq;
    size_t len = snprintf(NULL, 0, "sgt %ld\n", freq) + 1;

    content = malloc(sizeof(char) * len);
    if (content == NULL)
        return;
    sprintf(content, "sgt %ld\n", freq);
    list_add(&client->output_messages, content);
}
