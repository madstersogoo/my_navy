/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "../lib/include/my.h"

void launch_player_one(char **argv)
{
    int connection;
    pid_t process_id;
    process_id = getpid();
    message_player_one(process_id);
    while (connection != 1) {
        connection = signal(SIGUSR1, handling);
    }
    if (connection == 1)
        connected_enemy();
}

void launch_player_two(char **argv)
{
    pid_t process_id;
    process_id = getpid();
    message_player_two(process_id);
    kill(argv[1], SIGUSR1);
    my_putstr(argv[1]);
    int connection = signal(SIGUSR2, handling);
}

int handling(int signum)
{
    if (signum == SIGUSR1)
        return (1);
    else
        return (0);
}

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
