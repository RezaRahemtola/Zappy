/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** eggs
*/

#include <malloc.h>
#include "types.h"

egg_t *create_egg(size_t x, size_t y, bool emit_event)
{
    (void)emit_event;
    static size_t count = 0;
    egg_t *egg = malloc(sizeof(egg_t));

    if (egg == NULL)
        return NULL;
    egg->x = x;
    egg->y = y;
    egg->id = count++;
    return egg;
}
