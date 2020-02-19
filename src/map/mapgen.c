/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include "get_next_line.h"
#include "my.h"

char **remove_bowt(int n, int lg, char **map)
{
    int compt;

    for (compt = my_strlen(map[lg]); compt != 0; compt--) {
        if (map[lg][compt] == '.' && n != 0) {
            map[lg][compt] = 'B';
            n--;
        }
        if (n == 0)
            return (map);
    }
    return (NULL);
}

char **pos_capt(char *line)
{
    int n = 10;
    char **str = malloc(sizeof(char *) * (n + 2));
    int ijk[] = {0, 0, 0};
    str[0] = malloc(sizeof(char) * (my_strlen(line)) + 1);
    while (line[ijk[0]] != '\0') {
        if (line[ijk[0]] == ':') {
            str[ijk[1]][ijk[2]] = '\0';
            ijk[2] = 0;
            ijk[1]++;
            str[ijk[1]] = malloc(sizeof(char) * (my_strlen(line)) + 1);
        } else {
            str[ijk[1]][ijk[2]] = line[ijk[0]];
            ijk[2]++;
        }
        ijk[0]++;
    }
    str[ijk[1]][ijk[2]] = '\0';
    str[ijk[1] + 1] = NULL;
    return (str);
}

char **map_navy(void)
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
