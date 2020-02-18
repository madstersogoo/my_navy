/*
** EPITECH PROJECT, 2019
** getnextline
** File description:
** getnextline
*/

#include "get_next_line.h"

static strchain_t *my_reader(const int door, long *all, char *box, int size)
{
    strchain_t *temp;
    strchain_t *chain;

    chain = malloc(sizeof(*chain));
    if (chain == NULL)
        return (NULL);
    temp = chain;
    chain->str = box;
    while (size == READ_SIZE) {
        box = malloc(READ_SIZE);
        size = read(door, box, READ_SIZE);
        temp->next = malloc(sizeof(*temp));
        if (temp->next == NULL)
            return (NULL);
        temp = temp->next;
        temp->str = box;
        *all += size;
    }
    return (chain);
}

static void my_extractor(strchain_t *chain, char *buffer, long int len)
{
    long int i = -1;
    strchain_t *temp;
    while (len > READ_SIZE) {
        while (++i < READ_SIZE)
            buffer[i] = chain->str[i];
        len -= READ_SIZE;
        buffer += READ_SIZE;
        temp = chain->next;
        free(chain->str);
        free(chain);
        chain = temp;
        i = -1;
    }
    while (++i < len)
        buffer[i] = chain->str[i];
    free(chain->str);
    free(chain);
}

char *my_read(const int fd, long int *full_len)
{
    char *box = malloc(READ_SIZE);

    if (box == NULL)
        return (NULL);
    int size = read(fd, box, READ_SIZE);
    if (size == -1)
        return (NULL);
    *full_len = size;
    strchain_t *chain = my_reader(fd, full_len, box, size);
    if (chain == NULL)
        return (NULL);
    char *buffer = malloc(*full_len + 1);
    if (buffer == NULL)
        return (NULL);
    my_extractor(chain, buffer, *full_len);
    buffer[*full_len] = '\0';
    return (buffer);
}

char *my_strncpy(char const *src, int fin, int debut)
{
    char *dest = malloc(sizeof(char) * (fin-debut)+1);
    int i = 0;

    if (dest == NULL)
        return (NULL);
    while (debut < fin) {
        dest[i] = src[debut];
        debut++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *get_next_line(int fd)
{
    if (fd == -1)
        return (NULL);
    static long int full_len = 0;
    static int pos = 0;
    int save = pos;
    char *dest;
    static char *str = NULL;
    if (str == NULL)
        str = my_read(fd, &full_len);
    if (str == NULL || pos >= full_len)
        return (NULL);
    while (pos < full_len && str[pos] != '\n')
        pos++;
    dest = my_strncpy(str, pos, save);
    save = pos;
    pos++;
    return (dest);
}
