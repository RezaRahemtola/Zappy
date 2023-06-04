/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** server
*/

#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>
#include "server.h"
#include "network.h"

bool running;

static void sig_handler(int sig)
{
    if (sig == SIGINT)
        running = false;
}

void launch_server(params_t *params)
{
    socket_t *server = init_socket(params->port);

    if (server == NULL)
        return;
    running = true;
    signal(SIGINT, &sig_handler);
    while (running) {
        // TODO
    }
    free(server);
}
