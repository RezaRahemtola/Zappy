/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** incantation
*/

#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include "types.h"
#include "utils.h"
#include "commands/events.h"

void emit_incant_start_event(player_t *pl, list_t *clients)
{
    size_t len = snprintf(NULL, 0, "pic %ld %ld %ld", pl->x, pl->y, pl->level);
    char *content = malloc(sizeof(char) * (len + 1));
    char *tmp = NULL;
    client_t *client = NULL;
    list_t *evt_clients = clients;

    sprintf(content, "pic %ld %ld %ld", pl->x, pl->y, pl->level);
    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->player != NULL && client->player->x == pl->x
        && client->player->y == pl->y && client->player->level == pl->level) {
            len = snprintf(NULL, 0, " %ld", client->player->id) + 1;
            tmp = malloc(sizeof(char) * len);
            sprintf(tmp," %ld", client->player->id);
            content = new_strcat(content, tmp, true, true);
        }
    }
    send_event(evt_clients, new_strcat(content, "\n", true, false), true);
}

void emit_incant_end_event(size_t x, size_t y, bool success, list_t *clients)
{
    size_t len = snprintf(NULL, 0, "pie %ld %ld %d\n", x, y, success) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "pie %ld %ld %d\n", x, y, success);
    send_event(clients, content, true);
}
