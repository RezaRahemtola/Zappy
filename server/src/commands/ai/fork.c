/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** fork AI command
*/

#include <malloc.h>
#include <string.h>
#include "parameters.h"
#include "commands/functions.h"
#include "commands/events.h"

void fork_end_func(list_t *args, client_t *client, server_t *serv, char **res)
{
    emit_egg_layed_event(client->player, serv, client->team);
    base_end_func(args, client, serv, res);
}

void fork_player(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    (void)serv;
    egg_t *egg = create_egg(client->player->x, client->player->y, true);
    char *message = strdup(SUCCESS_COMMAND_AI);

    if (egg == NULL || message == NULL) {
        free(egg);
        free(message);
        return;
    }
    list_add(&client->team->eggs, egg);
    *result = message;
    emit_egg_laying_event(client->player->id, serv->clients);
}
