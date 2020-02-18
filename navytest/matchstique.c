/*
** EPITECH PROJECT, 2020
** match
** File description:
** match
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_parcour(char *str, char c, int t)
{
    int compt;

    for (compt = 0; compt < t; compt++)
        str[compt] = c;
    str[compt] = '\0';
    return (str);
}

char **my_alloc(int t)
{
    char **map;
    int compt;

    map = malloc(sizeof(char *) * (t + 3));
    for (compt = 0; compt < (t + 2); compt++)
        map[compt] = malloc(sizeof(char *) * (t + 2) + 3);
    map[compt] = NULL;
    return (map);
}

char **gener_map(int t)
{
    char **map;
    int c = 1;

    map = my_alloc(t);
    map[0] = my_parcour(map[0], '*', (t * 2) + 1);
    for (c = 1; c < t + 1; c++) {
        map[c] = my_parcour(map[c], ' ', (t * 2) + 1);
        map[c][0] = '*';
        map[c][t * 2] = '*';
    }
    map[t + 1] = my_parcour(map[t + 1], '*', (t * 2) + 1);
    return (map);
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    int t = my_get_nbr(av[1]);
    int pt = my_get_nbr(av[2]);
    char **map;

    if (t == 0)
        return (84);
    if (t < 1 || t > 99)
        return (84);
    if (pt == 0 && pt < 1)
        return (84);
    map = gener_map(t);
    map = my_run(t, map);
    drow_map(map);
    pt = interface_play(map, t, pt);
    if (pt == 84)
        return (0);
    free (map);
    return (pt);
}

