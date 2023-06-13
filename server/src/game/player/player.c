/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** player
*/

#include <malloc.h>
#include <stdlib.h>
#include "game/player.h"
#include "commands/events.h"

void destroy_player(player_t *player)
{
    if (player == NULL)
        return;
    free(player->inventory);
    free(player);
}

inventory_t *create_inventory(size_t base_food)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (inventory == NULL)
        return NULL;
    inventory->food = base_food;
    inventory->deraumere = 0;
    inventory->linemate = 0;
    inventory->mendiane = 0;
    inventory->phiras = 0;
    inventory->sibur = 0;
    inventory->thystame = 0;
    return inventory;
}

static player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    inventory_t *inventory = create_inventory(BASE_PLAYER_FOOD);
    static size_t id = 1;
    short orientation = rand() % 5;

    if (player == NULL || inventory == NULL) {
        free(player);
        free(inventory);
        return NULL;
    }
    player->id = id++;
    player->inventory = inventory;
    player->x = 0;
    player->y = 0;
    player->level = 1;
    player->orientation = orientation != 0 ? orientation : 1;
    gettimeofday(&player->last_eat, NULL);
    return player;
}

void init_player(client_t *client, server_t *server)
{
    player_t *player = create_player();
    egg_t *egg = NULL;
    list_t *eggs = client->team->eggs;
    size_t index = rand() % list_size(eggs);

    if (player == NULL)
        return;
    for (size_t i = 0; i < index; i++)
        eggs = eggs->next;
    egg = eggs->data;
    player->x = egg->x;
    player->y = egg->y;
    list_remove_index(&client->team->eggs, index, free);
    client->player = player;
    emit_new_player_event(client, server);
}
