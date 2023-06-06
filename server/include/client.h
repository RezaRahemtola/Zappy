/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** client
*/

#pragma once

#include "my_list.h"

client_t *create_client(int fd, sockaddr_in_t address);
void destroy_client(client_t *client);
