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
#include "network/network.h"
#include "client.h"

static bool running(bool val)
{
    static bool running = true;

    if (val == false)
        running = val;
    return running;
}

static void sig_handler(int sig)
{
    if (sig == SIGINT)
        running(false);
}

static void destroy_server(server_t *server)
{
    if (server == NULL)
        return;
    list_free(server->clients, (free_func)destroy_client);
    free(server->socket);
    destroy_params(server->params);
    free(server);
}

static server_t *create_server(params_t *params)
{
    server_t *server = malloc(sizeof(server_t));
    socket_t *sock = init_server_socket(params->port);

    if (server == NULL || sock == NULL) {
        destroy_server(server);
        free(sock);
        return NULL;
    }
    server->socket = sock;
    server->clients = NULL;
    server->params = params;
    return server;
}

void launch_server(params_t *params)
{
    server_t *server = create_server(params);
    fd_set readfds;
    fd_set writefds;

    if (server == NULL)
        return;
    signal(SIGINT, &sig_handler);
    while (running(true)) {
        reset_fd_sets(&readfds, &writefds, server);
        if (select(FD_SETSIZE, &readfds, &writefds, NULL, NULL) >= 0) {
            handle_connections(server, &readfds);
            handle_messages(server, &readfds);
        }
        write_to_clients(server->clients, &writefds);
        disconnect_clients(server);
    }
    destroy_server(server);
}
