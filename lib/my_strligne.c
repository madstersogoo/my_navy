/*
** EPITECH PROJECT, 2019
** fonction perso
** File description:
** my_strligne.c
*/

#include "include/my.h"

int my_strligne(char const *str)
{
        int i = 0;
        while (str[i] != '\n')
        {
                i = i + 1;
        }
        return (i);
}
