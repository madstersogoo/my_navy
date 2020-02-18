/*
** EPITECH PROJECT, 2020
** affichage
** File description:
** affichage
*/

#include "my.h"

char *my_getline(void)
{
    char *line = NULL;
    size_t len = 1;
    ssize_t nread;

    line = malloc(sizeof(char) * 20000);
    if ((nread = getline(&line, &len, stdin)) != -1) {
        line[nread - 1] = '\0';
        return (line);
    } else
        return (NULL);
}

void aff(int *lnm)
{
    write(1, "Player removed ", 15);
    my_put_nbr(lnm[1]);
    write(1, " match(es) from line ", 21);
    my_put_nbr(lnm[0]);
    my_putchar('\n');
}

void aff_ia(int lg, int n)
{
    write(1, "AI removed ", 11);
    my_put_nbr(n);
    write(1, " match(es) from line ", 21);
    my_put_nbr(lg);
    my_putchar('\n');
}

int my_put_nbr(int nb)
{
    if (nb < 0){
        my_putchar(45);
        nb = nb * -1;
    }
    int i;
    if (nb >= 0){
        if (nb >= 10){
            i = (nb % 10);
            nb = (nb - i) / 10;
            my_put_nbr(nb);
            my_putchar(48 + i);
        }
        else
            my_putchar(48 + nb % 10);
    }
}
