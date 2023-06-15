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
#include "utils.h"
#include "game/player.h"

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
    team_t *team = get_team_by_name(msg, server->params->teams);
    size_t size = 0;

    if (team == NULL || list_size(team->eggs) == 0) {
        list_add(&client->output_messages, strdup(MESSAGE_KO));
        return;
    }
    size = list_size(team->eggs);
    client->team = team;
    if (strcmp(team->name, GUI_TEAM_NAME) != 0) {
        send_welcome(client, server, size - 1);
        init_player(client, server);
    } else {
        list_remove_index(&team->eggs, rand() % size, free);
    }
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
