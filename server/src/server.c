/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** server
*/

#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"
#include "network.h"
#include "client.h"

bool running;

static void sig_handler(int sig)
{
    if (sig == SIGINT)
        running = false;
}

static server_t *create_server(params_t *params)
{
    server_t *server = malloc(sizeof(server_t));
    socket_t *sock = init_socket(params->port);

    if (server == NULL || sock == NULL) {
        free(server);
        return NULL;
    }
    server->socket = sock;
    server->clients = NULL;
    return server;
}

static void destroy_server(server_t *server)
{
    if (server == NULL)
        return;
    close_clients(server->clients);
    list_free(server->clients, free);
    free(server);
}

void launch_server(params_t *params)
{
    server_t *server = create_server(params);
    fd_set readfds;
    fd_set writefds;

    if (server == NULL)
        return;
    running = true;
    signal(SIGINT, &sig_handler);
    while (running) {
        reset_fd_sets(&readfds, &writefds, server);
        if (select(FD_SETSIZE, &readfds, &writefds, NULL, NULL) >= 0) {
            handle_connections(server, &readfds);
            handle_messages(server, &readfds);
        }

    }
    destroy_server(server);
}
