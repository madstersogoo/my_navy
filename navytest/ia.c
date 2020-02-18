/*
** EPITECH PROJECT, 2020
** ia
** File description:
** ia
*/

#include "my.h"

int legal_line_bot(int lg, int t)
{
    if (lg < 0) {
        return (84);
    }
    if (lg == 0 || lg > t) {
        return (84);
    }
    return (0);
}

int legal_matches_bot(int n, int pt, int m)
{
    if (n < 0) {
        return (84);
    }
    if (n == 0) {
        return (84);
    }
    if (n > pt) {
        return (84);
    }
    if (n > m) {
        return (84);
    }
    return (0);
}

char **ia(char **map, int t, int pt)
{
    int lg = 0;
    int n = 0;
    int m = 0;
    char line[1024];
    my_putstr("AI's turn...");
    do {
        do {
            lg = random()%666;
        } while (legal_line_bot(lg, t) != 0);
        n = random()%666;
        m = compt_barre(lg, map);
    } while (legal_matches_bot(n, pt, m) != 0);
    aff_ia(lg, n);
    map = remove_barre(n, lg, map);
    drow_map(map);
    return (map);
}
