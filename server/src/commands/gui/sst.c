/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** sst
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commands/functions.h"

void sst(list_t *args, client_t *client, server_t *server, char **result)
{
    (void)client;
    size_t new_freq = 0;
    size_t len = 0;

    if (list_size(args) == 2) {
        new_freq = atol(args->next->data);
        if (new_freq > 0) {
            server->params->freq = new_freq;
            len = snprintf(NULL, 0, "sst %ld\n", new_freq) + 1;
            *result = malloc(sizeof(char) * len);
            sprintf(*result, "sst %ld\n", new_freq);
            return;
        }
    }
    *result = strdup(UNKNOWN_COMMAND_PARAMETER);
}
