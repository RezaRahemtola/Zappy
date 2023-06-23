/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** end_game
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "commands/events.h"

void emit_endgame_event(const char *team, list_t *clients)
{
    size_t len = snprintf(NULL, 0, "seg %s\n", team);
    char *content = malloc(sizeof(char) * (len + 1));

    if (content == NULL)
        return;
    sprintf(content, "seg %s\n", team);
    send_event(clients, content, true);
}
