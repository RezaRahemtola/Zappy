/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** client
*/

#include <unistd.h>
#include "network.h"

void close_clients(list_t *clients)
{
    list_t *tmp = clients;
    client_t *client = NULL;

    while (tmp != NULL) {
        client = tmp->data;
        if (client->socket.fd > 0)
            close(client->socket.fd);
        tmp = tmp->next;
    }
}
