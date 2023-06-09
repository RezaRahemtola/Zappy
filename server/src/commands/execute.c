/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** commands execution
*/

#include <stddef.h>
#include <time.h>
#include "commands/commands.h"

static void execute_client_command(client_t *client, server_t *server)
{
    command_t *cmd = client->commands->data;

    if (client->disconnected)
        return;
    if (cmd->starting_time == 0) {
        cmd->starting_time = time(NULL);
        cmd->function(cmd->args, client, server, &cmd->result);
    } else if (difftime(time(NULL), cmd->starting_time)
        >= cmd->time / server->params->freq) {
        list_add(&client->output_messages, cmd->result);
        list_remove_head(&client->commands, (free_func)destroy_command);
    }
}

void execute_commands(server_t *server)
{
    list_t *clients = server->clients;
    client_t *client = NULL;

    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->commands == NULL)
            continue;
        execute_client_command(client, server);
    }
}
