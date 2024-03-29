/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** client
*/

#include <unistd.h>
#include <malloc.h>
#include "network/network.h"
#include "game/player.h"
#include "commands/commands.h"

void destroy_client(client_t *client)
{
    if (client == NULL)
        return;
    close(client->socket->fd);
    free(client->socket);
    list_free(client->output_messages, free);
    destroy_player(client->player);
    list_free(client->commands, (free_func)destroy_command);
    free(client);
}

client_t *create_client(int fd, sockaddr_in_t address)
{
    client_t *client = malloc(sizeof(client_t));
    socket_t *sock = init_client_socket(fd, address);

    if (client == NULL || sock == NULL) {
        free(client);
        free(sock);
        return NULL;
    }
    client->socket = sock;
    client->team = NULL;
    client->output_messages = NULL;
    client->commands = NULL;
    client->disconnected = false;
    client->player = NULL;
    return client;
}
