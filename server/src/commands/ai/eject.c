/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** eject AI command
*/

#include <malloc.h>
#include <string.h>
#include "parameters.h"
#include "utils.h"
#include "commands/functions.h"

static void remove_eggs(list_t *teams, size_t x, size_t y)
{
    team_t *team = NULL;
    egg_t *egg = NULL;
    list_t *eggs = NULL;

    for (; teams != NULL; teams = teams->next) {
        team = teams->data;
        eggs = team->eggs;
        for (size_t i = 0; eggs != NULL; i++) {
            egg = eggs->data;
            if (egg->x == x && egg->y == y) {
                eggs = eggs->next;
                list_remove_index(&team->eggs, i, free);
                continue;
            }
            eggs = eggs->next;
        }
    }
}

void eject(list_t *args, client_t *client, server_t *serv, char **result)
{
    (void)args;
    list_t *clients = serv->clients;
    client_t *curr = NULL;
    bool ejected = false;

    for (; clients != NULL; clients = clients->next) {
        curr = clients->data;
        if (curr->player != NULL && curr->player->id != client->player->id) {
            ejected = true;
            curr->player->x = get_x(curr->player->x, serv->params->width, &(mov_t){client->player->orientation,
                                                                                  FRONT}, 1);
            curr->player->y = get_y(curr->player->y, serv->params->height, &(mov_t){client->player->orientation,
                                                                                   FRONT}, 1);
            // TODO: emit eject to player
            // TODO: emit eject to GUI
        }
    }
    remove_eggs(serv->params->teams, client->player->x, client->player->y);
    *result = ejected ? strdup(SUCCESS_COMMAND_AI) : strdup(FAILED_COMMAND_AI);
}
