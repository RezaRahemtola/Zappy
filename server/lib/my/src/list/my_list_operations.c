/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** Operations on lists
*/

#include <stdlib.h>
#include "my_list.h"

size_t list_size(list_t *list)
{
    list_t *current = list;
    size_t size = 0;

    if (list == NULL)
        return (0);
    for (; current != NULL; size++)
        current = current->next;
    return (size);
}

void list_free(list_t *list, free_func free_func)
{
    list_t *current = list;
    list_t *tmp = NULL;

    while (current != NULL) {
        tmp = current->next;
        if (free_func != NULL)
            free_func(current->data);
        free(current);
        current = tmp;
    }
}
