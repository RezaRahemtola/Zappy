/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** incantation AI command
*/

#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "parameters.h"
#include "commands/functions.h"
#include "commands/incantation.h"
#include "commands/commands.h"

bool verify_incant(client_t *client, server_t *server)
{
    size_t level = client->player->level;
    incant_t incant = INCANT_DATA[level - 1];
    tile_t *tile = server->game->map[client->player->y][client->player->x];

    if (tile->linemate < incant.linemate || tile->deraumere < incant.deraumere
        || tile->sibur < incant.sibur || tile->mendiane < incant.mendiane
        || tile->phiras < incant.phiras || tile->thystame < incant.thystame)
        return false;
    // TODO: verify player (same tile and state)
    return true;
}

void incant_end_func(list_t *args, client_t *client, server_t *serv,
                     char **result)
{
    (void)args;
    size_t len = snprintf(NULL, 0, "Current level: %ld\n",
                          client->player->level) + 1;
    char *msg = NULL;

    if (strcmp(*result, FAILED_COMMAND_AI) == 0
        || !verify_incant(client, serv)) {
        list_add(&client->output_messages, strdup(FAILED_COMMAND_AI));
    } else {
        msg = malloc(sizeof(char) * len);
        sprintf(msg, "Current level: %ld\n", ++(client->player->level));
        list_add(&client->output_messages, msg);
        // TODO: remove resources from the map
    }
    list_remove_head(&client->commands, (free_func)destroy_command);
}

void incantation(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;

    if (!verify_incant(client, serv)) {
        *result = strdup(FAILED_COMMAND_AI);
        list_add(&client->output_messages, strdup(FAILED_COMMAND_AI));
        return;
    }
    *result = strdup("Elevation underway\n");
    list_add(&client->output_messages, strdup(*result));
    // TODO: send message to other clients too
}
