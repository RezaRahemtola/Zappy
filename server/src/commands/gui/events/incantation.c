/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** pnw
*/

#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "types.h"
#include "parameters.h"

void emit_incant_end_event(size_t x, size_t y, bool success, list_t *clients)
{
    client_t *client = NULL;
    size_t len = snprintf(NULL, 0, "pie %ld %ld %d\n", x, y, success) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "pie %ld %ld %d\n", x, y, success);
    for (; clients != NULL; clients = clients->next) {
        client = clients->data;
        if (client->team != NULL
        && strcmp(client->team->name, GUI_TEAM_NAME) == 0)
            list_add(&client->output_messages, strdup(content));
    }
    free(content);
}
