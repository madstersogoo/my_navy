/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "../lib/include/my.h"
#include "../src/stucture/structure.h"

struct memory* shared;

void launch_player_one(char **argv)
{
    pid_t process_id;
    process_id = getpid();
    message_player_one(process_id);
    signal(SIGUSR1, handling);
    pause ();
    connected_enemy();
    my_put_nbr(shared->pid);
    pid_t pid_player_two = shared->pid;
    kill(pid_player_two,SIGUSR2);
}

void launch_player_two(char **argv)
{
    pid_t pid2 = my_getnbr(argv[1]);
    pid_t process_id;
    process_id = getpid();
    shared->pid = process_id;
    message_player_two(process_id);
    sleep (10);
    kill(pid2, SIGUSR1);
    my_put_nbr(shared->pid);
    my_putstr(argv[1]);
    signal(SIGUSR2, handler);
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
