/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** network
*/

#pragma once

#include <netinet/in.h>

#define NETWORK_MAX_CLIENTS 100

typedef struct sockaddr_in sockaddr_in_t;
typedef struct sockaddr sockaddr_t;

typedef struct socket_s {
    int fd;
    sockaddr_in_t address;
    socklen_t len;
} socket_t;

socket_t *init_socket(size_t port);
