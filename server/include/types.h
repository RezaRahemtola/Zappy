/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** server
*/

#pragma once

#include <netinet/in.h>
#include <time.h>
#include "my_list.h"

// Network
typedef struct sockaddr_in sockaddr_in_t;
typedef struct sockaddr sockaddr_t;

typedef struct socket_s {
    int fd;
    sockaddr_in_t address;
    socklen_t len;
} socket_t;


// Parameters

typedef struct team_s {
    char *name;
    size_t clientsNb;
} team_t;

typedef struct params_s {
    size_t port;
    size_t width;
    size_t height;
    list_t *teams;
    size_t clientsNb;
    size_t freq;
} params_t;


// Main
typedef struct client_s {
    char *team;
    socket_t *socket;
    list_t *output_messages;
    bool disconnected;
    list_t *commands;
} client_t;

typedef struct server_s {
    socket_t *socket;
    list_t *clients;
    params_t *params;
} server_t;


// Commands
typedef void (*command_fct)(list_t *args, client_t *client,
    server_t *server, char **result);

typedef struct command_s {
    const char *name;
    command_fct function;
    list_t *args;
    char *result;
    size_t time;
    time_t starting_time;
} command_t;
