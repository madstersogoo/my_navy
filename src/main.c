/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "../lib/include/my.h"

int main(int argc, char **argv)
{
        if (argc != 2) {
                argument();
                return (1);
        }
        if (argv[1][0] == '-') {
                if (argv[1][1] == 'h') {
                        help();
                        return (1);
                }
        }
        return (0);
}
