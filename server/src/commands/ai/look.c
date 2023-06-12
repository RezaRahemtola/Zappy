/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** look AI command
*/

#include <malloc.h>
#include <string.h>
#include "parameters.h"
#include "commands/functions.h"
#include "utils.h"

static char *get_tile_content(size_t x, size_t y, player_t *player,
                            tile_t ***map)
{
    char *str = NULL;
    tile_t *tile = map[y][x];

    if (player->x == x && player->y == y)
        str = strdup(" player");
    for (size_t i = 0; i < tile->food; i++)
        str = new_strcat(str, " food", true, false);
    for (size_t i = 0; i < tile->linemate; i++)
        str = new_strcat(str, " linemate", true, false);
    for (size_t i = 0; i < tile->deraumere; i++)
        str = new_strcat(str, " deraumere", true, false);
    for (size_t i = 0; i < tile->sibur; i++)
        str = new_strcat(str, " sibur", true, false);
    for (size_t i = 0; i < tile->mendiane; i++)
        str = new_strcat(str, " mendiane", true, false);
    for (size_t i = 0; i < tile->phiras; i++)
        str = new_strcat(str, " phiras", true, false);
    for (size_t i = 0; i < tile->thystame; i++)
        str = new_strcat(str, " thystame", true, false);
    return str;
}

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
