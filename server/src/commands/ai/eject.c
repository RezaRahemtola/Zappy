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
#include "commands/events.h"

static void remove_egg(list_t **eggs, size_t index, team_t *team, bool remove)
{
    if (remove) {
        *eggs = (*eggs)->next;
        list_remove_index(&team->eggs, index, free);
    }
    *eggs = (*eggs)->next;
}

static void remove_eggs(list_t *teams, size_t x, size_t y, list_t *clients)
{
    team_t *team = NULL;
    egg_t *egg = NULL;
    list_t *eggs = NULL;

    for (; teams != NULL; teams = teams->next) {
        team = teams->data;
        eggs = team->eggs;
        for (size_t i = 0; eggs != NULL; i++) {
            egg = eggs->data;
            emit_dead_egg_event(egg->id, clients);
            remove_egg(&eggs, i, team, (egg->x == x && egg->y == y));
        }
    }
}

static short get_eject_dir(short orientation)
{
    switch (orientation) {
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 2;
        default:
            return 0;
    }
}

static void eject_player(client_t *curr, short orientation, server_t *serv)
{
    short dir = get_eject_dir(orientation);
    size_t len = snprintf(NULL, 0, "eject: %d\n", dir);
    char *msg = malloc(sizeof(char) * (len + 1));

    if (msg == NULL)
        return;
    sprintf(msg, "eject: %d\n", dir);
    curr->player->x = get_x(curr->player->x, serv->params->width,
                            &(mov_t){orientation,FRONT}, 1);
    curr->player->y = get_y(curr->player->y, serv->params->height,
                            &(mov_t){orientation, FRONT}, 1);
    list_add(&curr->output_messages, msg);
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
            eject_player(curr, client->player->orientation, serv);
        }
    }
    remove_eggs(serv->params->teams, client->player->x, client->player->y,
                serv->clients);
    *result = ejected ? strdup(SUCCESS_COMMAND_AI) : strdup(FAILED_COMMAND_AI);
    if (ejected)
        emit_eject_player_event(client, serv);
}
