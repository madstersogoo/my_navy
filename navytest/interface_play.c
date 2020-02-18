/*
** EPITECH PROJECT, 2020
** math
** File description:
** math
*/

#include "my.h"

int lose(char **map)
{
    for (int y = 1; map[y] != NULL; y++) {
        if (compt_barre(y, map) != 0)
            return (84);
    }
    return (0);
}

int interface_play(char **map, int t, int pt)
{
    while (42) {
        map = player(map, t, pt);
        if (map == NULL)
            return (84);
        if (lose(map) == 0) {
            my_putstr("You lost, too bad...");
            return (2);
        }
        map = ia(map, t, pt);
        if (map == NULL)
            return (84);
        if (lose(map) == 0) {
            my_putstr("I lost... snif... but I'll get you next time!!");
            return (1);
        }
    }
}
