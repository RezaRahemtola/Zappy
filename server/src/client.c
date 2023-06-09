/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** client
*/

#include <unistd.h>
#include <malloc.h>
#include "network/network.h"

static void write_to_client(list_t *messages, client_t *client)
{
    char *message = NULL;

    if (client->disconnected)
        return;
    while (messages != NULL) {
        message = messages->data;
        dprintf(client->socket->fd, "%s", message);
        messages = messages->next;
    }
}

void write_to_clients(list_t *clients, fd_set *writefds)
{
    client_t *client = NULL;

    while (clients != NULL) {
        client = clients->data;
        if (FD_ISSET(client->socket->fd, writefds)) {
            write_to_client(client->output_messages, client);
            list_free(client->output_messages, free);
            client->output_messages = NULL;
        }
        clients = clients->next;
    }
}

void destroy_client(client_t *client)
{
    if (client == NULL)
        return;
    close(client->socket->fd);
    free(client->socket);
    list_free(client->output_messages, free);
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
    client->disconnected = false;
    return client;
}
