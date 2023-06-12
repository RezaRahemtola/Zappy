/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** tile utils
*/

#include <string.h>
#include "utils.h"

static bool can_add(size_t tile, size_t inv, int nb)
{
    if (nb < 0 && (int)tile + nb >= 0)
        return true;
    if (nb >= 0 && (int)inv - nb >= 0)
        return true;
    return false;
}

static bool add_resource_to_tile_helper(tile_t ***map, player_t *p,
                                        const char *e, int nb)
{
    if (strcmp(e, "mendiane") == 0 && can_add(map[p->y][p->x]->mendiane,
                                            p->inventory->mendiane, nb)) {
        map[p->y][p->x]->mendiane += nb;
        p->inventory->mendiane -= nb;
        return true;
    }
    if (strcmp(e, "phiras") == 0 && can_add(map[p->y][p->x]->phiras,
                                            p->inventory->phiras, nb)) {
        map[p->y][p->x]->phiras += nb;
        p->inventory->phiras -= nb;
        return true;
    }
    if (strcmp(e, "thystame") == 0 && can_add(map[p->y][p->x]->thystame,
                                            p->inventory->thystame, nb)) {
        map[p->y][p->x]->thystame += nb;
        p->inventory->thystame -= nb;
        return true;
    }
    return false;
}

static bool add_resource_to_tile(tile_t ***map, player_t *p,
                                const char *e, int nb)
{
    if (strcmp(e, "linemate") == 0 && can_add(map[p->y][p->x]->linemate,
                                            p->inventory->linemate, nb)) {
        map[p->y][p->x]->linemate += nb;
        p->inventory->linemate -= nb;
        return true;
    }
    if (strcmp(e, "deraumere") == 0 && can_add(map[p->y][p->x]->deraumere,
                                            p->inventory->deraumere, nb)) {
        map[p->y][p->x]->deraumere += nb;
        p->inventory->deraumere -= nb;
        return true;
    }
    if (strcmp(e, "sibur") == 0 && can_add(map[p->y][p->x]->sibur,
                                            p->inventory->sibur, nb)) {
        map[p->y][p->x]->sibur += nb;
        p->inventory->sibur -= nb;
        return true;
    }
    return add_resource_to_tile_helper(map, p, e, nb);
}

bool add_elem_to_tile(tile_t ***map, player_t *player, const char *e,
                    int nb)
{
    size_t x = player->x;
    size_t y = player->y;

    if (strcmp(e, "food") == 0 && can_add(map[y][x]->food,
                                        player->inventory->food, nb)) {
        map[y][x]->food += nb;
        player->inventory->food -= nb;
        return true;
    }
    return add_resource_to_tile(map, player, e, nb);
}

char *get_tile_content(size_t x, size_t y, player_t *player, tile_t ***map)
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
