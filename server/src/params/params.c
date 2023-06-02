/*
** EPITECH PROJECT, 2023
** server
** File description:
** parsing.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "parameters.h"

static params_t *init_params(void)
{
    params_t *params = malloc(sizeof(params_t));

    if (params == NULL)
        return NULL;
    params->port = PARAMS_DEFAULT_PORT;
    params->width = PARAMS_DEFAULT_WIDTH;
    params->height = PARAMS_DEFAULT_HEIGHT;
    params->clientsNb = PARAMS_DEFAULT_CLIENTS;
    params->freq = PARAMS_DEFAULT_FREQ;
    return params;
}

void destroy_params(params_t *params)
{
    if (params == NULL)
        return;
    free(params->teams);
    free(params);
}

static void parse_opt(int opt, char *const *argv, params_t *params, bool *err)
{
    switch (opt) {
        case 'p':
            setNbParam(&params->port, err);
            break;
        case 'x':
            setNbParam(&params->width, err);
            break;
        case 'y':
            setNbParam(&params->height, err);
            break;
        case 'c':
            setNbParam(&params->clientsNb, err);
            break;
        case 'f':
            setNbParam(&params->freq, err);
            break;
        case 'n':
            setTeams(argv, params, err);
            break;
        default:
            *err = true;
    }
}

params_t *get_params(int argc, char *const *argv)
{
    bool error = false;
    params_t *params = init_params();
    int option = 0;

    while ((option = getopt(argc, argv, ":p:x:y:n:c:f")) != -1) {
        parse_opt(option, argv, params, &error);
        if (error) {
            fprintf(stderr, "Incorrect value for %c.\n", option);
            destroy_params(params);
            return NULL;
        }
    }
    return params;
}
