/*
** EPITECH PROJECT, 2020
** tableau
** File description:
** tableau
*/

#include"my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_get_nbr(char *str)
{
    int c = 0;
    int r = 0;

    for (c = 0; str[c] != '\0'; c++) {
        if (str[c] < '0' || str[c] > '9')
            return (0);
        r += str[c] - 48;
        r = r * 10;
    }
    r = r / 10;
    if (str[0] == '-')
        r = r * - 1;
    return (r);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i = i + 1;
    }
    my_putchar('\n');
    return (0);
}

char **my_run(int t, char **map)
{
    int x = t;
    int y = 1;
    int c = 0;

    for (c = 0; y <= t; c++) {
        x = (t - c);
        while (x < (t + c + 1)) {
            map[y][x] = '|';
            x++;
        }
        y++;
    }
    return (map);
}

void drow_map(char **map)
{
    int compt;

    for (compt = 0; map[compt] != NULL; compt++)
        my_putstr(map[compt]);
    my_putchar('\n');
}
