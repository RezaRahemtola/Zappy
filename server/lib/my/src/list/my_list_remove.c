/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** List removing functions
*/

#include <stdlib.h>
#include "my_list.h"

static void remove_data(list_t *node, list_t **list, free_func free_func)
{
    list_t *prev = node->prev;
    list_t *next = node->next;

    if (prev == NULL)
        *list = next;
    else
        prev->next = next;
    if (next != NULL)
        next->prev = prev;
    if (free_func != NULL)
        free_func(node->data);
    free(node);
}

void list_remove(list_t **list, void *data, equals_func eq_func,
free_func free_func)
{
    list_t *current = *list;

    while (current != NULL) {
        if (eq_func(current->data, data)) {
            remove_data(current, list, free_func);
            return;
        }
        current = current->next;
    }
}

void list_remove_index(list_t **list, size_t index, free_func free_func)
{
    list_t *current = *list;

    if (index >= list_size(current))
        return;
    for (size_t i = 0; current != NULL; current = current->next, i++) {
        if (i == index) {
            remove_data(current, list, free_func);
            return;
        }
    }
}

void list_remove_head(list_t **list, free_func free_func)
{
    remove_data(*list, list, free_func);
}
