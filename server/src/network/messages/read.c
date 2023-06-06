/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** read
*/

#include <unistd.h>
#include <stdio.h>
#include "network/network.h"

void read_message(client_t *client)
{
    char buffer[NETWORK_MSG_SIZE];
    ssize_t nb_bytes = 0;

    nb_bytes = read(client->socket->fd, &buffer, NETWORK_MSG_SIZE);
    buffer[nb_bytes] = '\0';
    printf("Received %s\n", buffer);
}
