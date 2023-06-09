/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** player
*/

#include <malloc.h>
#include "game/player.h"
#include "commands/events.h"

void destroy_player(player_t *player)
{
    if (player == NULL)
        return;
    free(player->inventory);
    free(player);
}

static inventory_t *create_player_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (inventory == NULL)
        return NULL;
    inventory->food = BASE_PLAYER_FOOD;
    inventory->deraumere = 0;
    inventory->linemate = 0;
    inventory->mendiane = 0;
    inventory->phiras = 0;
    inventory->sibur = 0;
    inventory->thystame = 0;
    return inventory;
}

static player_t *create_player(size_t id)
{
    player_t *player = malloc(sizeof(player_t));
    inventory_t *inventory = create_player_inventory();

    if (player == NULL || inventory == NULL) {
        free(player);
        free(inventory);
        return NULL;
    }
    player->id = id;
    player->inventory = inventory;
    player->x = 0;
    player->y = 0;
    player->level = 1;
    player->orientation = 1;
    return player;
}

void init_player(client_t *client, server_t *server)
{
    player_t *player = create_player(server->player_nb);

    if (player == NULL)
        return;
    client->player = player;
    server->player_nb++;
    emit_new_player_event(client, server);
}
