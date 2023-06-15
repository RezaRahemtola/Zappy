/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** client disconnect
*/

#include <string.h>
#include <stdlib.h>
#include "client.h"
#include "parameters.h"
#include "commands/events.h"

static bool find_by_fd(client_t *current, client_t *sample)
{
    return current->socket->fd == sample->socket->fd;
}

static void disconnect_client(server_t *server, client_t *client)
{
    list_t *teams = server->params->teams;
    team_t *team = NULL;
    egg_t *egg = NULL;
    size_t x = rand() % server->params->width;
    size_t y = rand() % server->params->height;

    for (; teams != NULL; teams = teams->next) {
        team = teams->data;
        if (client->team != NULL
        && strcmp(client->team->name, team->name) == 0) {
            egg = create_egg(x, y, false);
            list_add(&team->eggs, egg);
            break;
        }
    }
    if (client->player != NULL)
        emit_dead_player_event(client, server);
}

void disconnect_clients(server_t *server)
{
    list_t *clients = server->clients;
    list_t *to_remove = NULL;
    client_t *client = NULL;

    while (clients != NULL) {
        client = clients->data;
        if (client->disconnected) {
            disconnect_client(server, client);
            list_add(&to_remove, client);
        }
        clients = clients->next;
    }
    clients = to_remove;
    while (clients != NULL) {
        list_remove(&server->clients, clients->data,
                    (equals_func)find_by_fd, (free_func) destroy_client);
        clients = clients->next;
    }
    list_free(to_remove, NULL);
}
