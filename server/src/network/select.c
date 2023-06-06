/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** select
*/

#include <stdio.h>
#include "network.h"

void handle_connections(server_t *server, fd_set *readfds)
{
    int fd = 0;

    if (FD_ISSET(server->socket->fd, readfds)) {
        fd = accept(server->socket->fd, NULL, &server->socket->len);
        if (fd == -1) {
            perror("Accept connection failed");
            return;
        }
        // TODO: create in client list and move this outside
        dprintf(fd, "WELCOME\n");
    }
}

void handle_messages(server_t *server, fd_set *readfds)
{
    char buffer[NETWORK_MSG_SIZE];
    list_t *clients = server->clients;
    client_t *client = NULL;

    while (clients != NULL) {
        client = clients->data;
        if (FD_ISSET(client->socket.fd, readfds)) {
            // TODO
        }
        clients = clients->next;
    }
}
