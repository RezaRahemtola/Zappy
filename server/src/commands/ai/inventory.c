/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** connect_nbr
*/

#include <stdio.h>
#include <malloc.h>
#include "commands/functions.h"

void inventory(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    (void)serv;
    inventory_t *inv = client->player->inventory;
    size_t len = snprintf(NULL, 0, "[ food %ld, linemate %ld, deraumere %ld, "
                        "sibur %ld, mendiane %ld, phiras %ld, thystame %ld ]\n",
                        inv->food, inv->linemate, inv->deraumere, inv->sibur,
                        inv->mendiane, inv->phiras, inv->thystame) + 1;

    *result = malloc(sizeof(char) * len);
    if (*result == NULL)
        return;
    sprintf(*result, "[ food %ld, linemate %ld, deraumere %ld, "
            "sibur %ld, mendiane %ld, phiras %ld, thystame %ld ]\n",
            inv->food, inv->linemate, inv->deraumere, inv->sibur,
            inv->mendiane, inv->phiras, inv->thystame);
}
