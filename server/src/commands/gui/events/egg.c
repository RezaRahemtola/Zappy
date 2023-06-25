/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** pnw
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "commands/events.h"

void emit_egg_laying_event(size_t player_id, list_t *clients)
{
    size_t len = snprintf(NULL, 0, "pfk %ld\n", player_id) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "pfk %ld\n", player_id);
    send_event(clients, content, true);
}

static size_t get_laid_egg_nb(team_t *team, size_t x, size_t y)
{
    egg_t *egg = NULL;
    list_t *eggs = team->eggs;

    for (; eggs != NULL; eggs = eggs->next) {
        egg = eggs->data;
        if (egg->x == x && egg->y == y)
            return egg->id;
    }
    return 0;
}

void emit_egg_layed_event(player_t *player, server_t *serv, team_t *team)
{
    size_t x = player->x;
    size_t y = player->y;
    size_t egg = get_laid_egg_nb(team, x, y);
    size_t len = snprintf(NULL, 0, "enw %ld %ld %ld %ld\n", egg,
                        player->id, x, y) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "enw %ld %ld %ld %ld\n", egg, player->id, x, y);
    send_event(serv->clients, content, true);
}

void emit_dead_egg_event(size_t id, list_t *clients)
{
    size_t len = snprintf(NULL, 0, "edi %ld\n", id) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "edi %ld\n", id);
    send_event(clients, content, true);
}

void emit_connect_egg(size_t id, player_t *player, list_t *clients)
{
    size_t len = snprintf(NULL, 0, "ebo %ld %ld %ld %ld\n", id, player->id,
                        player->x, player->y);
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "ebo %ld %ld %ld %ld\n", id);
    send_event(clients, content, true);
}
