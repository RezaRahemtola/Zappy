/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** incantation
*/

#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include "types.h"
#include "parameters.h"

void emit_incant_end_event(size_t x, size_t y, bool success, list_t *clients)
{
    size_t len = snprintf(NULL, 0, "pie %ld %ld %d\n", x, y, success) + 1;
    char *content = malloc(sizeof(char) * len);

    if (content == NULL)
        return;
    sprintf(content, "pie %ld %ld %d\n", x, y, success);
    send_event(clients, content, true);
}
