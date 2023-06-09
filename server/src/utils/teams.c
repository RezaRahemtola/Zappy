/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** teams utils
*/

#include <string.h>
#include "types.h"

team_t *get_team_by_name(const char *name, list_t *teams)
{
    team_t *team = NULL;

    while (teams != NULL) {
        team = teams->data;
        if (strcmp(name, team->name) == 0)
            return team;
        teams = teams->next;
    }
    return NULL;
}
