/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include "my.h"

void printu(void)
{
    write(1, "Error: ", 7);
    my_putstr("invalid output (positive number expected)");
}

void printd(void)
{
    write(1, "Error: ", 7);
    my_putstr("this line is out of range");
}

void printt(void)
{
    write(1, "Error: ", 7);
    my_putstr("you have to remove at least one match");
}

void printq(int pt)
{
    write(1, "Error: you cannot remove more than ", 35);
    my_put_nbr(pt);
    my_putstr(" matches per turn");
}

void printc(void)
{
    write(1, "Error: ", 7);
    my_putstr("not enough matches on this line");
}
