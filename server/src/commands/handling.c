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

static command_t *create_cmd(const command_t *base, list_t *args)
{
    command_t *command = malloc(sizeof(command_t));

    if (command == NULL)
        return NULL;
    command->name = base->name;
    command->args = args;
    command->function = base->function;
    command->result = NULL;
    command->time = base->time;
    command->starting_time = 0;
    return command;
}

void handle_command(list_t *args, client_t *client)
{
    char *name = NULL;
    command_t *cmd = NULL;

    if (list_size(args) < 1)
        return;
    name = args->data;
    for (size_t i = 0; COMMANDS[i].name != NULL; i++) {
        if (strcmp(COMMANDS[i].name, name) == 0
        && list_size(client->commands) < MAX_COMMANDS_PER_CLIENT) {
            cmd = create_cmd(&COMMANDS[i], args);
            list_add(&client->commands, cmd);
            break;
        }
    }
}
