/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** commands execution
*/

#include <stddef.h>
#include <string.h>
#include "commands/commands.h"
#include "utils.h"

static void execute_client_command(client_t *client, server_t *server)
{
    command_t *cmd = client->commands->data;

    if (client->disconnected)
        return;
    if (cmd->start.tv_usec == 0) {
        gettimeofday(&cmd->start, NULL);
        cmd->function(cmd->args, client, server, &cmd->result);
    } else if (check_time(cmd->start, cmd->time, server->params->freq)) {
        list_add(&client->output_messages, strdup(cmd->result));
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
