/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** commands handling
*/

#include <string.h>
#include "commands/list.h"

void handle_command(list_t *args, client_t *client, server_t *server)
{
    char *cmd = NULL;

    if (list_size(args) < 1)
        return;
    cmd = args->data;
    for (size_t i = 0; COMMANDS[i].name != NULL; i++) {
        if (strcmp(COMMANDS[i].name, cmd) == 0) {
            COMMANDS[i].function(args, client, server);
            break;
        }
    }
}
