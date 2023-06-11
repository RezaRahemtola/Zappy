/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** player utils
*/

#include <stddef.h>
#include "types.h"

player_t *get_player_by_id(list_t *clients, size_t id)
{
    client_t *client = NULL;

    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->player != NULL && client->player->id == id)
            return client->player;
    }
    return NULL;
}
