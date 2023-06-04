/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** network
*/

#pragma once

#include "server.h"

#define NETWORK_MAX_CLIENTS 100

// Socket
socket_t *init_socket(size_t port);

// FD sets
void reset_fd_sets(fd_set *readfds, fd_set *writefds, server_t *server);

// Select helpers
void handle_connections(server_t *server, fd_set *readfds);
