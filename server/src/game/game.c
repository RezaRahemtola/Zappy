/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** player
*/

#include <malloc.h>
#include <string.h>
#include "game/game.h"
#include "game/map.h"
#include "utils.h"
#include "game/player.h"

void destroy_game(game_t *game, params_t *params)
{
    destroy_map(game->map, params->width, params->height);
    free(game);
}

void print_map(tile_t ***map, size_t width, size_t height)
{
    printf("\n\nINNNNNNNNNNNNNNNNNN\n\n");
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            printf("---------------------------------------------\n");
            printf("map[%lu][%lu]\n", i, j);
            printf("food = %lu\n", map[i][j]->food);
            printf("linemate = %lu\n", map[i][j]->linemate);
            printf("deraumere = %lu\n", map[i][j]->deraumere);
            printf("sibur = %lu\n", map[i][j]->sibur);
            printf("mendiane = %lu\n", map[i][j]->mendiane);
            printf("phiras = %lu\n", map[i][j]->phiras);
            printf("thystame = %lu\n", map[i][j]->thystame);
            printf("---------------------------------------------\n");
        }
    }
    printf("\n\nOUUUUUUUUUT\n\n");
}

game_t *create_game(params_t *params)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return NULL;
    game->map = create_map(params->width, params->height);
    game->map = fill_map(game->map, params->width, params->height);
    return game;
}

static void check_hunger_death(client_t *client)
{
    if (client->player->inventory->food == 0) {
        list_add(&client->output_messages, strdup(AI_DEAD));
        client->disconnected = true;
        return;
    }
    gettimeofday(&client->player->last_eat, NULL);
}

void eat_food(server_t *server)
{
    list_t *clients = server->clients;
    client_t *client = NULL;
    inventory_t *inv = NULL;

    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->player != NULL && check_time(client->player->last_eat,
                                        FOOD_DURATION, server->params->freq)) {
            inv = client->player->inventory;
            inv->food--;
            check_hunger_death(client);
        }
    }
}
