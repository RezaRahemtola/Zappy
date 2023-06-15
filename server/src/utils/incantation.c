/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** player utils
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "types.h"
#include "commands/incantation.h"
#include "commands/commands.h"

void remove_incant_resources(const incant_t *incant, tile_t *tile)
{
    tile->linemate -= incant->linemate;
    tile->deraumere -= incant->deraumere;
    tile->sibur -= incant->sibur;
    tile->mendiane -= incant->mendiane;
    tile->phiras -= incant->phiras;
    tile->thystame -= incant->thystame;
}

void dispatch_incant_success(client_t *client, list_t *clients)
{
    size_t len = snprintf(NULL, 0, "Current level: %ld\n",
                        client->player->level) + 1;
    char *msg = malloc(sizeof(char) * len);
    client_t *current = NULL;
    size_t old_lvl = client->player->level;

    if (msg == NULL)
        return;
    sprintf(msg, "Current level: %ld\n", old_lvl + 1);
    for (; clients != NULL; clients = clients->next) {
        current = clients->data;
        if (current->player != NULL
            && current->player->x == client->player->x
            && current->player->y == client->player->y
            && current->player->level == old_lvl) {
            current->player->level++;
            list_add(&current->output_messages, strdup(msg));
        }
    }
    free(msg);
}

static void slave_incant_zombie(list_t *args, client_t *client, server_t *serv,
                                char **result)
{
    (void)args;
    (void)(client);
    (void)(serv);
    (void)result;
}

static void slave_incant_end(list_t *args, client_t *client, server_t *serv,
                                char **result)
{
    (void)args;
    (void)(serv);
    (void)result;
    list_remove_head(&client->commands, (free_func)destroy_command);
}

command_t *create_slave_incant_cmd(void)
{
    command_t *command = malloc(sizeof(command_t));

    if (command == NULL)
        return NULL;
    command->name = "SlaveIncantation";
    command->args = NULL;
    command->function = slave_incant_zombie;
    command->end_func = slave_incant_end;
    command->result = NULL;
    command->time = INCANT_TIME;
    command->start = (struct timeval){0};
    return command;
}
