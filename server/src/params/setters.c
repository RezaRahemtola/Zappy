/*
** EPITECH PROJECT, 2023
** server
** File description:
** parsing.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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

static team_t *create_team(char *name)
{
    team_t *team = malloc(sizeof(team_t));

    if (team == NULL)
        return NULL;
    team->name = strdup(name);
    if (team->name == NULL)
        return NULL;
    team->clientsNb = 0;
    return team;
}

void destroy_team(team_t *team)
{
    if (team == NULL)
        return;
    free(team->name);
    free(team);
}

void set_teams(char *const *argv, params_t *params, bool *error)
{
    size_t i = 0;
    team_t *team = NULL;

    if (params->teams == NULL) {
        team = create_team(GUI_TEAM_NAME);
        list_add(&params->teams, team);
    }
    optind--;
    for (; argv[optind + i] != NULL && argv[optind + i][0] != '-'; i++) {
        team = create_team(argv[optind + i]);
        if (team == NULL) {
            *error = true;
            list_free(params->teams, free);
            return;
        }
        list_add(&params->teams, team);
    }
}

void set_teams_clients_nb(params_t *params)
{
    list_t *teams = params->teams;
    team_t *team = NULL;

    while (teams != NULL) {
        team = teams->data;
        team->clientsNb = params->clientsNb;
        teams = teams->next;
    }
}
