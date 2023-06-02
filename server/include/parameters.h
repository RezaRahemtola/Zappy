/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** parameters
*/

#pragma once

#define PARAMS_DEFAULT_PORT 4242
#define PARAMS_DEFAULT_WIDTH 42
#define PARAMS_DEFAULT_HEIGHT 42
#define PARAMS_DEFAULT_CLIENTS 1
#define PARAMS_DEFAULT_FREQ 100

#include <stdbool.h>
#include <stddef.h>

typedef struct params_s {
    size_t port;
    size_t width;
    size_t height;
    char **teams;
    size_t clientsNb;
    size_t freq;
} params_t;

// Utils
params_t *get_params(int argc, char *const *argv);
void destroy_params(params_t *params);

// Setters
void setNbParam(size_t *storage, bool *error);
void setTeams(char *const *argv, params_t *params, bool *error);
