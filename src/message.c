/*
** EPITECH PROJECT, 2019
** navy
** File description:
** message
*/

#include "../lib/include/my.h"

void message_player_one(int pid)
{
        my_putstr("my_pid:  ");
        my_put_nbr(pid);
        my_putstr("\nwaiting for enemy connection...\n");
}

void message_player_two(int pid)
{
        my_putstr("my_pid:  ");
        my_put_nbr(pid);
        my_putchar('\n');
}

void connected_enemy(void)
{
        my_putstr("enemy connected\n");
}
