/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** direction AI commands
*/

#include <string.h>
#include "commands/functions.h"

void right(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    (void)serv;
    player_t *player = client->player;

    player->orientation++;
    if (player->orientation > 4)
        player->orientation = 1;
    *result = strdup(SUCCESS_COMMAND_AI);
}

void left(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    (void)serv;
    player_t *player = client->player;

    player->orientation--;
    if (player->orientation < 1)
        player->orientation = 4;
    *result = strdup(SUCCESS_COMMAND_AI);
}

void forward(list_t *args, client_t *client, server_t *serv, char **result)
{
    player_t *player = client->player;
    size_t width = serv->params->width;
    size_t height = serv->params->height;

    switch (player->orientation) {
        case 1:
            player->y = (player->y == 0) ? height - 1 : (player->y - 1);
            break;
        case 2:
            player->x = (player->x + 1 >= width) ? 0 : player->x + 1;
            break;
        case 3:
            player->y = (player->y + 1 >= height) ? 0 : player->y + 1;
            break;
        case 4:
            player->x = (player->x == 0) ? width - 1 : player->x - 1;
        default:
            (void)args;
    }
    *result = strdup(SUCCESS_COMMAND_AI);
}
