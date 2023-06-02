/*
** EPITECH PROJECT, 2023
** server
** File description:
** checks
*/

#include <string.h>
#include "parameters.h"

static void check_teams(char **teams, bool *error)
{
    if (teams == NULL) {
        *error = true;
        return;
    }
    for (size_t i = 0; teams[i] != NULL; i++) {
        for (size_t j = 1; teams[i + j] != NULL; j++)
            *error = (strcmp(teams[i], teams[i + j]) == 0) ? true : *error;
    }
}

void check_params(params_t *params, bool *error)
{
    check_teams(params->teams, error);
}
