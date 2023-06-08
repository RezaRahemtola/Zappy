/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** parsing
*/

#include <string.h>
#include <malloc.h>
#include "my_list.h"

list_t *split_message(char *message)
{
    char *sep = " ";
    char *token = strtok(message, sep);
    list_t *result = NULL;
    char *tmp = NULL;

    while (token != NULL) {
        tmp = strdup(token);
        if (tmp == NULL) {
            list_free(result, free);
            return NULL;
        }
        list_add(&result, tmp);
        token = strtok(NULL, sep);
    }
    return result;
}
