/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** player gui commands
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commands/functions.h"
#include "utils.h"

static size_t get_player_id(list_t *args)
{
    size_t result = 0;
    char *str = NULL;

    if (list_size(args) != 2)
        return 0;
    str = args->next->data;
    if (strlen(str) < 2)
        return 0;
    str[0] = ' ';
    result = atol(str);
    if (result <= 0)
        return 0;
    return result;
}

void ppo(list_t *args, client_t *client, server_t *server, char **result)
{
    (void)client;
    player_t *pl = NULL;
    size_t id = get_player_id(args);
    size_t len = 0;

    if (id > 0) {
        pl = get_player_by_id(server->clients, id);
        if (pl != NULL) {
            len = snprintf(NULL, 0, "ppo %ld %ld %ld %d\n",
                        pl->id, pl->x, pl->y, pl->orientation) + 1;
            *result = malloc(sizeof(char) * len);
            sprintf(*result, "ppo %ld %ld %ld %d\n",
                        pl->id, pl->x, pl->y, pl->orientation);
            return;
        }
    }
    *result = strdup(UNKNOWN_COMMAND_PARAMETER);
}

void plv(list_t *args, client_t *client, server_t *server, char **result)
{
    (void)client;
    player_t *pl = NULL;
    size_t id = get_player_id(args);
    size_t len = 0;

    if (id > 0) {
        pl = get_player_by_id(server->clients, id);
        if (pl != NULL) {
            len = snprintf(NULL, 0, "ppo %ld %ld\n",
                        pl->id, pl->level) + 1;
            *result = malloc(sizeof(char) * len);
            sprintf(*result, "ppo %ld %ld\n",
                        pl->id, pl->level);
            return;
        }
    }
    *result = strdup(UNKNOWN_COMMAND_PARAMETER);
}

static void set_pin_result(char **result, player_t * player, inventory_t *inv)
{
    size_t len = snprintf(NULL, 0,
                        "pin %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
                        player->id, player->x, player->y, inv->food,
                        inv->linemate, inv->deraumere,
                        inv->sibur, inv->mendiane,
                        inv->phiras, inv->thystame) + 1;

    *result = malloc(sizeof(char) * len);
    sprintf(*result, "pin %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
            player->id, player->x, player->y, inv->food,
            inv->linemate, inv->deraumere,
            inv->sibur, inv->mendiane,
            inv->phiras, inv->thystame);
}

void pin(list_t *args, client_t *client, server_t *server, char **result)
{
    (void)client;
    player_t *player = NULL;
    size_t id = get_player_id(args);

    if (id > 0) {
        player = get_player_by_id(server->clients, id);
        if (player != NULL) {
            set_pin_result(result, player, player->inventory);
            return;
        }
    }
    *result = strdup(UNKNOWN_COMMAND_PARAMETER);
}
