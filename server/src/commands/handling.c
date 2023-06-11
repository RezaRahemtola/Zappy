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
#include "parameters.h"

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
    command->start = (struct timeval){0};
    return command;
}

static void handle_command_type(command_t *commands, const char *err,
                                list_t *args, client_t *client)
{
    const char *name = args->data;
    command_t *cmd = NULL;
    bool found = false;

    for (size_t i = 0; commands[i].name != NULL; i++) {
        if (strcmp(commands[i].name, name) == 0
        && list_size(client->commands) < MAX_COMMANDS_PER_CLIENT) {
            cmd = create_cmd(&commands[i], args);
            list_add(&client->commands, cmd);
            found = true;
            break;
        }
    }
    if (!found) {
        list_add(&client->output_messages, strdup(err));
        list_free(args, free);
    }
}

void handle_command(list_t *args, client_t *client)
{
    if (list_size(args) < 1)
        return;
    if (strcmp(client->team->name, GUI_TEAM_NAME) == 0)
        handle_command_type( GUI_COMMANDS, UNKNOWN_COMMAND_GUI, args, client);
    else
        handle_command_type(AI_COMMANDS, FAILED_COMMAND_AI, args, client);
}
