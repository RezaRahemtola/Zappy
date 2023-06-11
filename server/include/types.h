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
    list_t *eggs;
} team_t;

typedef struct params_s {
    size_t port;
    size_t width;
    size_t height;
    list_t *teams;
    size_t clientsNb;
    size_t freq;
} params_t;


// Game
typedef struct inventory_s {
    size_t food;
    size_t linemate;
    size_t deraumere;
    size_t sibur;
    size_t mendiane;
    size_t phiras;
    size_t thystame;
} inventory_t;

typedef struct player_s {
    size_t id;
    inventory_t *inventory;
    size_t x;
    size_t y;
    short orientation;
    size_t level;
} player_t;

typedef struct egg_s {
    size_t x;
    size_t y;
    size_t id;
} egg_t;

typedef inventory_t tile_t;
typedef struct game_s {
    tile_t ***map;
} game_t;


// Main
typedef struct client_s {
    team_t *team;
    socket_t *socket;
    list_t *output_messages;
    bool disconnected;
    list_t *commands;
    player_t *player;
} client_t;

typedef struct server_s {
    socket_t *socket;
    list_t *clients;
    params_t *params;
    game_t *game;
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
