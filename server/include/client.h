/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** client
*/

#pragma once

#include "my_list.h"
#include "types.h"

client_t *create_client(int fd, sockaddr_in_t address);
void destroy_client(client_t *client);

// Data handling
void write_to_clients(list_t *clients, fd_set *writefds);

// Disconnect
void disconnect_clients(server_t *server);
