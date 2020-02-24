/*
** EPITECH PROJECT, 2019
** my_bsq
** File description:
** my_bsq
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#ifndef READ_SIZE
#define READ_SIZE 4000
#endif /* READ_SIZE */

typedef struct strchain {
    char *str;
    struct strchain *next;
} strchain_t;

char *my_read(const int port, long int *full_len);
char *get_next_line(int fd);

#endif /* GET_NEXT_LINE_H_ */
