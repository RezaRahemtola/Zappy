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
    command->starting_time = 0;
    return command;
}

static void handle_gui_command(const char *name, list_t *args, client_t *client)
{
    command_t *cmd = NULL;
    bool found = false;

    for (size_t i = 0; GUI_COMMANDS[i].name != NULL; i++) {
        if (strcmp(GUI_COMMANDS[i].name, name) == 0
        && list_size(client->commands) < MAX_COMMANDS_PER_CLIENT) {
            cmd = create_cmd(&GUI_COMMANDS[i], args);
            list_add(&client->commands, cmd);
            found = true;
            break;
        }
    }
    if (!found) {
        list_add(&client->output_messages, strdup(UNKNOWN_COMMAND_GUI));
        list_free(args, free);
    }
}

static void handle_ai_command(const char *name, list_t *args, client_t *client)
{
    command_t *cmd = NULL;
    bool found = false;

    for (size_t i = 0; AI_COMMANDS[i].name != NULL; i++) {
        if (strcmp(AI_COMMANDS[i].name, name) == 0
        && list_size(client->commands) < MAX_COMMANDS_PER_CLIENT) {
            cmd = create_cmd(&AI_COMMANDS[i], args);
            list_add(&client->commands, cmd);
            found = true;
            break;
        }
    }
    if (!found) {
        list_add(&client->output_messages, strdup(UNKNOWN_COMMAND_AI));
        list_free(args, free);
    }
}

void handle_command(list_t *args, client_t *client)
{
    char *name = NULL;

    if (list_size(args) < 1)
        return;
    name = args->data;
    if (strcmp(client->team, GUI_TEAM_NAME) == 0)
        handle_gui_command(name, args, client);
    else
        handle_ai_command(name, args, client);
}
