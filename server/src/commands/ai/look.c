/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** look AI command
*/

#include <string.h>
#include "parameters.h"
#include "commands/functions.h"
#include "utils.h"

void look(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    player_t *player = client->player;
    char *tile = NULL;

    *result = strdup("[");
    tile = get_tile_content(player->x, player->y, player, serv->game->map);
    *result = new_strcat(*result, tile, true, false);
    *result = new_strcat(*result, " ]\n", true, false);
}
