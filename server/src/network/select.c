/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** select
*/

#include <stdio.h>
#include "server.h"

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
