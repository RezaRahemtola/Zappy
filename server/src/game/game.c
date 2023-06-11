/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** player
*/

#include <malloc.h>
#include "game/game.h"
#include "game/map.h"

void destroy_game(game_t *game, params_t *params)
{
    destroy_map(game->map, params->width, params->height);
    free(game);
}

game_t *create_game(params_t *params)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return NULL;
    game->map = create_map(params->width, params->height);
    return game;
}
