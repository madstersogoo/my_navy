/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include "../lib/include/my.h"

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid: only for the 2nd player.");
    my_putstr("  pid of the player.\n");
    my_putstr("     navy_positions: file representing the positions");
    my_putstr(" of the ships.\n");
}

void argument(void)
{
    my_putstr("second argument required\n");
    my_putstr("do ./navy -h for more information\n");
}
