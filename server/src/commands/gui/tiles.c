/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** tile commands
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commands/functions.h"

static int get_size(list_t *args, size_t pos, size_t max)
{
    int res = 0;

    if (list_size(args) < pos + 1)
        return -1;
    for (size_t i = 0; i < pos; i++)
        args = args->next;
    res = atoi(args->data);
    if (res == 0 && strcmp(args->data, "0") != 0)
        return -1;
    if (res > (int)max)
        return -1;
    return res;
}

static void bct_helper(size_t x, size_t y, server_t *server, char **result)
{
    inventory_t *inv = server->game->map[y][x];
    size_t len = snprintf(NULL, 0, "bct %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
        x, y, inv->food, inv->linemate, inv->deraumere, inv->sibur,
        inv->mendiane, inv->phiras, inv->thystame) + 1;
    *result = malloc(sizeof(char) * len);
    if (*result == NULL)
        return;
    sprintf(*result, "bct %ld %ld %ld %ld %ld %ld %ld %ld %ld\n", x, y,
    inv->food, inv->linemate, inv->deraumere, inv->sibur, inv->mendiane,
    inv->phiras, inv->thystame);
}

void bct(list_t *args, client_t *client, server_t *server, char **result)
{
    (void)client;
    int x = get_size(args, 1, server->params->width - 1);
    int y = get_size(args, 2, server->params->height - 1);

    if (x == -1 || y == -1 || list_size(args) != 3) {
        *result = strdup(UNKNOWN_COMMAND_PARAMETER_GUI);
        return;
    }
    bct_helper(x, y, server, result);
}

void mct(list_t *args, client_t *client, server_t *server, char **result)
{
    (void)args;
    (void)client;
    char *new = NULL;
    size_t len = 0;

    for (size_t y = 0; y < server->params->height; y++) {
        for (size_t x = 0; x < server->params->width; x++) {
            bct_helper(x, y, server, &new);
            len = *result == NULL ? 0 : strlen(*result);
            *result = realloc(*result, sizeof(char) * (len + strlen(new) + 1));
            len == 0 ? strcpy(*result, new) : strcat(*result, new);
            free(new);
        }
    }
}
