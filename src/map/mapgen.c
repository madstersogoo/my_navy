/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include "get_next_line.h"
#include "my.h"

char **map_navy()
{
    char **tab = malloc(sizeof(char *) * 10);
    int i = 0;
    int fd = open("./src/map/map.txt", O_RDONLY);
    while (i != 10) {
        tab[i] = get_next_line(fd);
        ++i;
    }
    tab[i] = 0;
    return (tab);
}
