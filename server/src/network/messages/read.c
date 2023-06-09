/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** read
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "network/network.h"
#include "client.h"
#include "network/messages.h"
#include "commands/commands.h"

static void send_welcome(client_t *client, server_t *server, size_t clientsNb)
{
    size_t w = server->params->width;
    size_t h = server->params->height;
    size_t len = snprintf(NULL, 0, "%ld\n%ld %ld\n", clientsNb, w, h) + 1;
    char *data = malloc(sizeof(char) * len);

    if (data == NULL)
        return;
    sprintf(data, "%ld\n%ld %ld\n", clientsNb, w, h);
    list_add(&client->output_messages, data);
}

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
    if (found == NULL || found->clientsNb == 0) {
        list_add(&client->output_messages, strdup(MESSAGE_KO));
        return;
    }
    client->team = found->name;
    found->clientsNb--;
    send_welcome(client, server, found->clientsNb);
}

static void handle_message(client_t *client, char *msg)
{
    list_t *cmd_args = split_message(msg);

    if (cmd_args == NULL)
        return;
    handle_command(cmd_args, client);
}

void read_message(client_t *client, server_t *server)
{
    char buffer[NETWORK_MSG_SIZE];
    ssize_t nb_bytes = 0;

    nb_bytes = read(client->socket->fd, &buffer, NETWORK_MSG_SIZE);
    if (nb_bytes == 0) {
        client->disconnected = true;
        return;
    }
    buffer[nb_bytes - 1] = '\0';
    if (client->team == NULL)
        handle_team_message(client, buffer, server);
    else
        handle_message(client, buffer);
}
