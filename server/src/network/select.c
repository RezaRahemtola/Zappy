/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** select
*/

#include <stdio.h>
#include "network/network.h"
#include "network/messages.h"
#include "client.h"

void handle_connections(server_t *server, fd_set *readfds)
{
    client_t *client = NULL;
    int fd = 0;

    if (FD_ISSET(server->socket->fd, readfds)) {
        fd = accept(server->socket->fd, NULL, &server->socket->len);
        if (fd == -1) {
            perror("Accept connection failed");
            return;
        }
        client = create_client(fd, server->socket->address);
        if (client == NULL) {
            perror("Client creation failed");
            return;
        }
        list_add(&server->clients, client);
        dprintf(fd, "WELCOME\n");
    }
}

void handle_messages(server_t *server, fd_set *readfds)
{
    list_t *clients = server->clients;
    client_t *client = NULL;

    while (clients != NULL) {
        client = clients->data;
        if (FD_ISSET(client->socket->fd, readfds))
            read_message(client, server);
        clients = clients->next;
    }
}
