/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** main.c
*/

#include <stdio.h>

static void display_usage(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ..."
    " -c clientsNb -f freq\n"
    "port\tis the port number\n"
    "width\tis the width of the world\n"
    "height\tis the height of the world\n"
    "nameX\tis the name of the team X\n"
    "clientsNb\tis the number of authorized clients per team\n"
    "freq\tis the reciprocal of time unit for execution of actions"
    );
}

int main(void)
{
    display_usage();
    return 0;
}
