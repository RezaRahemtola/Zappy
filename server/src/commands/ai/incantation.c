/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** incantation AI command
*/

#include <malloc.h>
#include <string.h>
#include "parameters.h"
#include "commands/functions.h"
#include "commands/events.h"
#include "commands/incantation.h"

void incantation(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    (void)serv;
    list_add(&client->output_messages, strdup("Begin incant"));
    *result = strdup("End incant");
}
