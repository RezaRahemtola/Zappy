/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** socket
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "network/network.h"

static socket_t *init_socket_error(const char *message, socket_t *sock)
{
    perror(message);
    free(sock);
    return NULL;
}

socket_t *init_client_socket(int fd, sockaddr_in_t address)
{
    socket_t *sock = malloc(sizeof(socket_t));

    if (sock == NULL)
        return NULL;
    sock->fd = fd;
    sock->address = address;
    sock->len = sizeof(address);
    return sock;
}

socket_t *init_server_socket(size_t port)
{
    socket_t *sock = malloc(sizeof(socket_t));

    if (sock == NULL)
        return NULL;
    sock->fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (sock->fd == -1)
        return init_socket_error("Failed to create socket fd", sock);
    sock->address.sin_family = AF_INET;
    sock->address.sin_port = htons(port);
    sock->address.sin_addr.s_addr = INADDR_ANY;
    sock->len = sizeof(sock->address);
    if (bind(sock->fd, (sockaddr_t *)&sock->address, sock->len) == -1)
        return init_socket_error("Failed to bind socket", sock);
    if (listen(sock->fd, NETWORK_MAX_CLIENTS) == -1)
        return init_socket_error("Failed to listen socket", sock);
    return (sock);
}
