/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** object commands
*/

#include <string.h>
#include "utils.h"
#include "commands/functions.h"

static const char* OBJECTS[] = {"food", "linemate", "deraumere",
                                "sibur", "mendiane", "phiras", "thystame",
                                NULL};

static bool valid_object(list_t *args)
{
    if (list_size(args) != 2)
        return false;
    for (size_t i = 0; OBJECTS[i] != NULL; i++) {
        if (strcmp(OBJECTS[i], args->next->data) == 0)
            return true;
    }
    return false;
}

void take_obj(list_t *args, client_t *client, server_t *serv, char **result)
{
    if (valid_object(args) && add_elem_to_tile(serv->game->map, client->player,
        args->next->data, -1)) {
        *result = strdup(SUCCESS_COMMAND_AI);
        return;
    }
    *result = strdup(FAILED_COMMAND_AI);
}

void set_obj(list_t *args, client_t *client, server_t *serv, char **result)
{
    if (valid_object(args) && add_elem_to_tile(serv->game->map, client->player,
        args->next->data, 1)) {
        *result = strdup(SUCCESS_COMMAND_AI);
        return;
    }
    *result = strdup(FAILED_COMMAND_AI);
}
