/*
** EPITECH PROJECT, 2023
** server
** File description:
** checks
*/

#include <string.h>
#include "parameters.h"

static bool duplicated_team(list_t *teams, const char *name)
{
    size_t count = 0;
    team_t *team = NULL;

    while (teams != NULL) {
        team = teams->data;
        if (strcmp(name, team->name) == 0)
            count++;
        teams = teams->next;
    }
    return count != 1;
}

static void check_teams(list_t *teams, bool *error)
{
    team_t *team = NULL;

    if (teams == NULL) {
        *error = true;
        return;
    }

    while (teams != NULL) {
        team = teams->data;
        if (duplicated_team(teams, team->name))
            *error = true;
        teams = teams->next;
    }
}

void check_params(params_t *params, bool *error)
{
    check_teams(params->teams, error);
}
