/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** server
*/

#include <stdbool.h>
#include <signal.h>
#include "server.h"

bool running = true;

static void sig_handler(int sig)
{
    if (sig == SIGINT)
        running = false;
}

void launch_server(params_t *params)
{
    signal(SIGINT, &sig_handler);
    while (running) {
        // TODO
    }
}
