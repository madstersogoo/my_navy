/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "../lib/include/my.h"

struct memory {
    int pid_player_two, move;
};

struct memory* shared;

void launch_player_one(char **argv)
{
    int connection;
    pid_t process_id;
    process_id = getpid();
    message_player_one(process_id);
    signal(SIGUSR1, handling);
    pause ();
    connected_enemy();
    my_put_nbr(pid_player_two);
    kill(pid_player_two,SIGUSR2);
}

void launch_player_two(char **argv)
{
    pid_t pid2 = my_getnbr(argv[1]);
    pid_t process_id;
    process_id = getpid();
    message_player_two(process_id);
    sleep (10);
    kill(pid2, SIGUSR1);
    signal(SIGUSR2, handler);
    my_putstr(argv[1]);
    pause ();
}

void handling(int signum)
{
    if (signum == SIGUSR1) {
    }
}

void handler(int signum)
{
    if (signum == SIGUSR2) {
    }
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
