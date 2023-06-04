/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** server
*/

#pragma once

#include "my_list.h"
#include <netinet/in.h>

// Network
typedef struct sockaddr_in sockaddr_in_t;
typedef struct sockaddr sockaddr_t;

typedef struct socket_s {
    int fd;
    sockaddr_in_t address;
    socklen_t len;
} socket_t;


// Communication
typedef struct client_s {
    socket_t socket;
} client_t;

typedef struct server_s {
    socket_t *socket;
    list_t *clients;
} server_t;


// Parameters
typedef struct params_s {
    size_t port;
    size_t width;
    size_t height;
    char **teams;
    size_t clientsNb;
    size_t freq;
} params_t;
