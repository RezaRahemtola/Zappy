/*
** EPITECH PROJECT, 2023
** server
** File description:
** parsing.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "parameters.h"

void setNbParam(size_t *storage, bool *error)
{
    size_t data = atol(optarg);

    if (data <= 0) {
        *error = true;
        return;
    }
    *storage = data;
}

void setTeams(char *const *argv, params_t *params, bool *error)
{
    // TODO
}
