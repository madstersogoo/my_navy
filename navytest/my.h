/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);
int my_get_nbr(char *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_putstr(char const *str);
char **my_run(int t, char **map);
void drow_map(char **map);
void aff(int *lnm);
void aff_ia(int lg, int n);
void printu(void);
void printd(void);
void printt(void);
void printq(int pt);
void printc(void);
char **ia(char **map, int t, int pt);
int compt_barre(int lg, char **map);
int interface_play(char **map, int t, int pt);
char **remove_barre(int n, int lg, char **map);
char **player(char **map, int t, int pt);
char *my_getline(void);
