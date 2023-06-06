/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** read
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "network/network.h"
#include "client.h"

static void handle_team_message(client_t *client, char *msg, server_t *server)
{
    list_t *teams = server->params->teams;
    team_t *team = NULL;
    team_t *found = NULL;

    while (teams != NULL && found == NULL) {
        team = teams->data;
        if (strcmp(msg, team->name) == 0)
            found = team;
        teams = teams->next;
    }
    if (found == NULL || found->clientsNb == 0)
        return;
    client->team = found->name;
    found->clientsNb--;
    dprintf(client->socket->fd, "%ld\n", found->clientsNb);
}

void read_message(client_t *client, server_t *server)
{
    char buffer[NETWORK_MSG_SIZE];
    ssize_t nb_bytes = 0;

    nb_bytes = read(client->socket->fd, &buffer, NETWORK_MSG_SIZE);
    buffer[nb_bytes - 1] = '\0';
    if (client->team == NULL)
        handle_team_message(client, buffer, server);
}
