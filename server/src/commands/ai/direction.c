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
