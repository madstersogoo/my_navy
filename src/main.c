/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "../lib/include/my.h"

int main(int argc, char **argv)
{
        if (argc == 1) {
                argument();
                return (1);
        }
        if (argv[1][0] == '-') {
                if (argv[1][1] == 'h') {
                        help();
                        return (1);
                }
        }
        if (argc == 2)
                launch_player_one(argv);
        if (argc == 3)
                launch_player_two(argv);
        return (0);
}

void launch_player_one(char **argv)
{
        pid_t process_id;
        process_id = getpid();
        message_player_one(process_id);
}

void launch_player_two(char **argv)
{
        pid_t process_id;
        process_id = getpid();
        message_player_two(process_id);
}
