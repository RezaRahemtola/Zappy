/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** player
*/

#include <string.h>
#include "game/game.h"
#include "commands/events.h"

bool check_endgame_team(team_t *team, list_t *clients)
{
    client_t *client = NULL;
    size_t count = 0;

    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->player != NULL
        && client->player->level == WIN_NEEDED_LEVEL
        && strcmp(team->name, client->team->name) == 0) {
            count++;
        }
    }
    return count >= WIN_NEEDED_PLAYERS;
}

bool check_endgame(server_t *server)
{
    list_t *teams = server->params->teams;
    team_t *team = NULL;

    for (; teams != NULL; teams = teams->next) {
        team = teams->data;
        if (check_endgame_team(team, server->clients)) {
            emit_endgame_event(team->name, server->clients);
            return true;
        }
    }
    return false;
}
