/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** str to word
*/
#include <stdlib.h>
#include "include/my.h"

int my_strlen_bn(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            j++;
        i++;
    }
    return (j);
}

char **my_str_to_word_array(char *str)
{
    int bn = my_strlen_bn(str);
    int j = 0;
    char **result = malloc(sizeof(char) * bn + 1);
    int i = 0;
    int x = 0;
    while (str[i] != '\0')
    {
            if (x == 0)
                    result[j] = malloc(sizeof(char) * my_strlen(str));
            if (str[i] != ' ') {
                    result[j][x] = str[i];
                    x++;
            }
            else {
                    j++;
                    x = 0;
            }
            i++;
    }
    return (result);
}

