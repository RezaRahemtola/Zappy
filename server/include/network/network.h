/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** network
*/

#pragma once

#include "parameters.h"

#define NETWORK_MAX_CLIENTS 100
#define NETWORK_MSG_SIZE 4092

// Socket
socket_t *init_server_socket(size_t port);
socket_t *init_client_socket(int fd, sockaddr_in_t address);

// FD sets
void reset_fd_sets(fd_set *readfds, fd_set *writefds, server_t *server);

// Select helpers
void handle_connections(server_t *server, fd_set *readfds);
void handle_messages(server_t *server, fd_set *readfds);
