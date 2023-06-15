/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** incantation AI command
*/

#include <string.h>
#include "parameters.h"
#include "commands/functions.h"
#include "commands/incantation.h"
#include "commands/commands.h"
#include "utils.h"
#include "commands/events.h"

static size_t count_incant_players(player_t *player, list_t *clients)
{
    size_t count = 0;
    client_t *client = NULL;

    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->player != NULL
            && client->player->x == player->x && client->player->y == player->y
            && client->player->level == player->level)
            count++;
    }
    return count;
}

static bool verify_incant(client_t *client, server_t *server)
{
    size_t level = client->player->level;
    incant_t incant = INCANT_DATA[level - 1];
    tile_t *tile = server->game->map[client->player->y][client->player->x];

    if (tile->linemate < incant.linemate || tile->deraumere < incant.deraumere
        || tile->sibur < incant.sibur || tile->mendiane < incant.mendiane
        || tile->phiras < incant.phiras || tile->thystame < incant.thystame)
        return false;
    return count_incant_players(client->player, server->clients)
            >= incant.players;
}

void incant_end_func(list_t *args, client_t *client, server_t *serv,
                    char **result)
{
    (void)args;
    player_t *player = client->player;
    tile_t *tile = serv->game->map[player->y][player->x];

    if (strcmp(*result, FAILED_COMMAND_AI) == 0
        || !verify_incant(client, serv)) {
        list_add(&client->output_messages, strdup(FAILED_COMMAND_AI));
        emit_incant_end_event(player->x, player->y, false, serv->clients);
    } else {
        remove_incant_resources(&INCANT_DATA[player->level - 1], tile);
        dispatch_incant_success(client, serv->clients);
        emit_incant_end_event(player->x, player->y, true, serv->clients);
    }
    list_remove_head(&client->commands, (free_func)destroy_command);
}

void incant(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    list_t *clients = serv->clients;
    player_t *pl = client->player;

    if (!verify_incant(client, serv)) {
        *result = strdup(FAILED_COMMAND_AI);
        list_add(&client->output_messages, strdup(FAILED_COMMAND_AI));
        return;
    }
    *result = strdup("Elevation underway\n");
    list_add(&client->output_messages, strdup(*result));
    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->player != NULL && client->player->x == pl->x
        && client->player->y == pl->y && client->player->level == pl->level
        && client->player->id != pl->id) {
            list_add(&client->output_messages, strdup(*result));
            list_add(&client->commands, create_slave_incant_cmd());
        }
    }
}
