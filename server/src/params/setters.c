/*
** EPITECH PROJECT, 2023
** server
** File description:
** parsing.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "parameters.h"

void set_nb_param(size_t *storage, bool *error)
{
    size_t data = atol(optarg);

    if (data <= 0) {
        *error = true;
        return;
    }
    *storage = data;
}

void set_teams(char *const *argv, params_t *params, bool *error)
{
    size_t i = 0;
    char **tmp = NULL;

    optind--;
    for (; argv[optind + i] != NULL && argv[optind + i][0] != '-'; i++) {
        tmp = realloc(params->teams, (i + 2) * sizeof(char *));
        if (tmp == NULL) {
            *error = true;
            return;
        }
        params->teams = tmp;
        params->teams[i] = argv[optind + i];
    }
    params->teams[i] = NULL;
}
