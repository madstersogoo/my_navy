/*
** EPITECH PROJECT, 2020
** playeur
** File description:
** playeur
*/

#include "my.h"

int legal_line(int lg, int t)
{
    if (lg < 0) {
        printu();
        return (84);
    }
    if (lg == 0 || lg > t) {
        printd();
        return (84);
    }
    return (0);
}

int legal_matches(int n, int pt, int m)
{
    if (n < 0) {
        printu();
        return (84);
    }
    if (n == 0) {
        printt();
        return (84);
    }
    if (n > pt) {
        printq(pt);
        return (84);
    }
    if (n > m) {
        printc();
        return (84);
    }
    return (0);
}

int compt_barre(int lg, char **map)
{
    int compt = 0;

    for (int i = 0; map[lg][i] != '\0'; i++)
        if (map[lg][i] == '|')
            compt++;
    return (compt);
}

char **remove_barre(int n, int lg, char **map)
{
    int compt;

    for (compt = my_strlen(map[lg]); compt != 0; compt--) {
        if (map[lg][compt] == '|' && n != 0) {
            map[lg][compt] = ' ';
            n--;
        }
        if (n == 0)
            return (map);
    }
    return (NULL);
}

char **player(char **map, int t, int pt)
{
    int lnm[] = {0, 0, 0};
    char *line;

    my_putstr("Your turn:");
    do {
        do {
            write(1, "Line: ", 6);
            line = my_getline();
            if (line == NULL)
                return (NULL);
            lnm[0] = my_get_nbr(line);
            free(line);
        } while (legal_line(lnm[0], t) != 0);
        write(1, "Matches: ", 9);
        line = my_getline();
        if (line == NULL)
            return (NULL);
        lnm[1] = my_get_nbr(line);
        lnm[2] = compt_barre(lnm[0], map);
    } while (legal_matches(lnm[1], pt, lnm[2]) != 0);
    aff(lnm);
    map = remove_barre(lnm[1], lnm[0], map);
    drow_map(map);
    return (map);
}
