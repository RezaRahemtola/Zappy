/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** player utils
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *new_strcat(char *str1, char *str2, bool free1, bool free2)
{
    size_t len1 = (str1 == NULL) ? 0 : strlen(str1);
    size_t len2 = (str2 == NULL) ? 0 : strlen(str2);
    char *new = NULL;

    if (len1 + len2 == 0)
        return NULL;
    new = malloc(sizeof(char) * (len1 + len2 + 1));
    if (str2 == NULL)
        strcpy(new, str1);
    else if (str1 == NULL)
        strcpy(new, str2);
    else {
        strcpy(new, str1);
        strcat(new, str2);
    }
    if (free1)
        free(str1);
    if (free2)
        free(str2);
    return new;
}
