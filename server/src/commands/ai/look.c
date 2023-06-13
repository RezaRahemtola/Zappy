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

static char *look_around_ns(player_t *pl, server_t *serv, size_t level,
    size_t center)
{
    size_t x_left = get_x(pl->x, serv->params->width,
                        &(mov_t){pl->orientation, LEFT}, level);
    size_t x_right = get_x(pl->x, serv->params->width,
                        &(mov_t){pl->orientation, RIGHT}, level);
    size_t min = (x_left > x_right) ? x_right : x_left;
    size_t max = (x_left > x_right) ? x_left : x_right;
    char *result = NULL;
    char *tile = NULL;

    for (size_t i = min; i <= max; i++) {
        tile = get_tile_content(i, center, pl, serv->game->map);
        result = new_strcat(result, tile, true, true);
        result = new_strcat(result, ",", true, false);
    }
    return result;
}

static char *look_around_ew(player_t *pl, server_t *serv, size_t level,
    size_t center)
{
    size_t y_left = get_y(pl->y, serv->params->height,
                        &(mov_t){pl->orientation, LEFT}, level);
    size_t y_right = get_y(pl->y, serv->params->height,
                        &(mov_t){pl->orientation, RIGHT}, level);
    size_t min = (y_left > y_right) ? y_right : y_left;
    size_t max = (y_left > y_right) ? y_left : y_right;
    char *result = NULL;
    char *tile = NULL;

    for (size_t i = min; i <= max; i++) {
        tile = get_tile_content(center, i, pl, serv->game->map);
        result = new_strcat(result, tile, true, true);
        result = new_strcat(result, ",", true, false);
    }
    return result;
}

void look(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    player_t *player = client->player;
    char *tile = NULL;
    size_t center = 0;
    bool is_ns = (player->orientation == 1 || player->orientation == 3);

    tile = get_tile_content(player->x, player->y, player, serv->game->map);
    *result = new_strcat("[", tile, false, true);
    for (size_t i = 1; i < player->level + 1; i++) {
        center = is_ns
            ? get_y(player->y, serv->params->height,
                &(mov_t){player->orientation, FRONT}, i)
            : get_x(player->x, serv->params->width,
                &(mov_t){player->orientation, FRONT}, i);
        tile = is_ns
            ? look_around_ns(player, serv, i, center)
            : look_around_ew(player, serv, i, center);
        *result = new_strcat(*result, tile, true, true);
    }
    *result = new_strcat(*result, " ]\n", true, false);
}
