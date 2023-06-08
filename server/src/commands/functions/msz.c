/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** msz
*/

#include <string.h>
#include "commands/functions.h"

void msz(list_t *args, client_t *client, server_t *server)
{
    (void)args;
    (void)server;
    char *content = strdup("msz X Y\n");

    if (content == NULL)
        return;
    list_add(&client->output_messages, content);
}
