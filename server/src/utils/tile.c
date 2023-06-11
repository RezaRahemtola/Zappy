/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** tile utils
*/

#include <string.h>
#include "types.h"

static bool add_resource_to_tile_helper(tile_t ***map, player_t *player,
                                        const char *e, int nb)
{
    size_t x = player->x;
    size_t y = player->y;

    if (strcmp(e, "mendiane") == 0 && (int)map[y][x]->mendiane + nb >= 0) {
        map[y][x]->mendiane += nb;
        player->inventory->mendiane -= nb;
        return true;
    }
    if (strcmp(e, "phiras") == 0 && (int)map[y][x]->phiras + nb >= 0) {
        map[y][x]->phiras += nb;
        player->inventory->phiras -= nb;
        return true;
    }
    if (strcmp(e, "thystame") == 0 && (int)map[y][x]->thystame + nb >= 0) {
        map[y][x]->thystame += nb;
        player->inventory->thystame -= nb;
        return true;
    }
    return false;
}

static bool add_resource_to_tile(tile_t ***map, player_t *player,
                                const char *e, int nb)
{
    size_t x = player->x;
    size_t y = player->y;

    if (strcmp(e, "linemate") == 0 && (int)map[y][x]->linemate + nb >= 0) {
        map[y][x]->linemate += nb;
        player->inventory->linemate -= nb;
        return true;
    }
    if (strcmp(e, "deraumere") == 0 && (int)map[y][x]->deraumere + nb >= 0) {
        map[y][x]->deraumere += nb;
        player->inventory->deraumere -= nb;
        return true;
    }
    if (strcmp(e, "sibur") == 0 && (int)map[y][x]->sibur + nb >= 0) {
        map[y][x]->sibur += nb;
        player->inventory->sibur -= nb;
        return true;
    }
    return add_resource_to_tile_helper(map, player, e, nb);
}

bool add_elem_to_tile(tile_t ***map, player_t *player, const char *e,
                    int nb)
{
    size_t x = player->x;
    size_t y = player->y;

    if (strcmp(e, "food") == 0 && (int)map[y][x]->food + nb >= 0) {
        map[y][x]->food += nb;
        player->inventory->food -= nb;
        return true;
    }
    return add_resource_to_tile(map, player, e, nb);
}
