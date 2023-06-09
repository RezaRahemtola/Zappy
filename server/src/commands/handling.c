/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** commands handling
*/

#include <string.h>
#include <malloc.h>
#include "commands/list.h"
#include "commands/commands.h"

void destroy_command(command_t *command)
{
    if (command == NULL)
        return;
    list_free(command->args, free);
    free(command);
}

static command_t *create_cmd(const char *name, list_t *args, command_fct fct)
{
    command_t *command = malloc(sizeof(command_t));

    if (command == NULL)
        return NULL;
    command->name = name;
    command->args = args;
    command->function = fct;
    return command;
}

void handle_command(list_t *args, client_t *client, server_t *server)
{
    char *name = NULL;
    command_t *cmd = NULL;

    if (list_size(args) < 1)
        return;
    name = args->data;
    for (size_t i = 0; COMMANDS[i].name != NULL; i++) {
        if (strcmp(COMMANDS[i].name, name) == 0
        && list_size(client->commands) < MAX_COMMANDS_PER_CLIENT) {
            cmd = create_cmd(name, args, COMMANDS[i].function);
            list_add(&client->commands, cmd);
            break;
        }
    }
}
