/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** client
*/

#include <unistd.h>
#include <malloc.h>
#include "network/network.h"

void destroy_client(client_t *client)
{
    if (client == NULL)
        return;
    close(client->socket->fd);
    free(client->socket);
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
    return client;
}
