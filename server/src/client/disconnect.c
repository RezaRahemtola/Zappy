/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** client disconnect
*/

#include <string.h>
#include "types.h"
#include "client.h"

static bool find_by_fd(client_t *current, client_t *sample)
{
    return current->socket->fd == sample->socket->fd;
}

static void decrement_team(server_t *server, client_t *client)
{
    list_t *teams = server->params->teams;
    team_t *team = NULL;

    while (teams != NULL) {
        team = teams->data;
        if (strcmp(client->team, team->name) == 0) {
            team->clientsNb++;
            break;
        }
        teams = teams->next;
    }
}

void disconnect_clients(server_t *server)
{
    list_t *clients = server->clients;
    list_t *to_remove = NULL;
    client_t *client = NULL;

    while (clients != NULL) {
        client = clients->data;
        if (client->disconnected) {
            decrement_team(server, client);
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
