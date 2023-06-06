/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** socket
*/

#include "network/network.h"

void reset_fd_sets(fd_set *readfds, fd_set *writefds, server_t *server)
{
    list_t *clients = server->clients;
    client_t *client = NULL;

    FD_ZERO(readfds);
    FD_ZERO(writefds);
    FD_SET(server->socket->fd, readfds);
    FD_SET(server->socket->fd, writefds);
    while (clients != NULL) {
        client = clients->data;
        if (client->socket->fd >= 0) {
            FD_SET(client->socket->fd, readfds);
            FD_SET(client->socket->fd, writefds);
        }
        clients = clients->next;
    }
}
