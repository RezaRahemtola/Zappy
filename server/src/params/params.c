/*
** EPITECH PROJECT, 2023
** server
** File description:
** params
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
    params->teams = NULL;
    params->clientsNb = PARAMS_DEFAULT_CLIENTS;
    params->freq = PARAMS_DEFAULT_FREQ;
    return params;
}

void destroy_params(params_t *params)
{
    if (params == NULL)
        return;
    list_free(params->teams, (free_func)destroy_team);
    free(params);
}

static void parse_nb_opt(int opt, params_t *params, bool *err)
{
    switch (opt) {
        case 'p':
            set_nb_param(&params->port, err);
            break;
        case 'x':
            set_nb_param(&params->width, err);
            break;
        case 'y':
            set_nb_param(&params->height, err);
            break;
        case 'c':
            set_nb_param(&params->clientsNb, err);
            break;
        case 'f':
            set_nb_param(&params->freq, err);
            break;
        default:
            break;
    }
}

static void parse_opt(int opt, char *const *argv, params_t *params, bool *err)
{
    switch (opt) {
        case 'p':
        case 'x':
        case 'y':
        case 'c':
        case 'f':
            parse_nb_opt(opt, params, err);
            break;
        case 'n':
            set_teams(argv, params, err);
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

    while ((option = getopt(argc, argv, ":p:x:y:n:c:f:")) != -1) {
        parse_opt(option, argv, params, &error);
        if (error) {
            fprintf(stderr, "Incorrect value for %c.\n", option);
            destroy_params(params);
            return NULL;
        }
    }
    set_teams_eggs(params);
    check_params(params, &error);
    if (error) {
        fprintf(stderr, "Parameter checks failed.\n");
        destroy_params(params);
        return NULL;
    }
    return params;
}
