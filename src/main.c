/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "../lib/include/my.h"

void launch_player_one(char **argv, memory_t* shared)
{
    pid_t process_id;
    process_id = getpid();
    message_player_one(process_id);
    signal(SIGUSR1, handling);
    pause ();
    connected_enemy();
    my_put_nbr(shared->pid);
    kill(shared->pid,SIGUSR2);
}

void launch_player_two(char **argv, memory_t* shared)
{
    pid_t pid2 = my_getnbr(argv[1]);
    shared->pid = getpid();
    message_player_two(shared->pid);
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
    memory_t* shared = malloc(sizeof(memory_t));
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
        launch_player_one(argv, shared);
    if (argc == 3)
        launch_player_two(argv, shared);
    return (0);
}
