/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** navy
*/


#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int	my_getnbr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strligne(char const *str);
int my_strlen(char const *str);
void help(void);
void argument(void);
void message_player_one(int pid);
void launch_player_one(char **argv);

#endif
