/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** returns a read of a fd
*/

#include "mysh.h"

static char *my_strcpy(char *str)
{
    char *src;
    int i;
    int k = 0;
    int size = 0;

    for (size = 0; str[size] != '\n'; size++);
    if ((src = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    for (i = 0; str[i] != '\n'; i++)
        src[i] = str[i];
    src[i] = 0;
    for (int j = i + 1; str[j]; j++)
        str[k++] = str[j];
    str[k] = '\0';
    return (src);
}

static char *concat(char *dest, char *src)
{
    int size_dest = 0;
    int size_src = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    char *new;

    if (!dest)
        size_dest = 0;
    else
        for (size_dest = 0; dest[size_dest]; size_dest++);
    for (size_src = 0; src[size_src]; size_src++);
    new = malloc(sizeof(char) * (size_dest + size_src + 1));
    if (dest)
        for (i = 0; dest[i]; i++)
            new[i] = dest[i];
    for (j = i; src[k]; j++)
        new[j] = src[k++];
    (dest) ? free(dest) : 0;
    new[j] = '\0';
    return (new);
}

char *read_next_n_bytes(int fd)
{
    char *tmp = malloc(sizeof(char) * (READ_SIZE + 1));
    int size = 0;

    if (!tmp || fd == -1)
        return (NULL);
    size = read(fd, tmp, READ_SIZE);
    tmp[size] = '\0';
    return (size <= 0 ? free(tmp), NULL : tmp);
}

static char *strcpy_last(char *temp)
{
    char *last;
    int size = 0;
    int i = 0;

    for (size = 0; temp[size] != 0; size++);
    if ((last = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    while (temp[i]) {
        last[i] = temp[i];
        i++;
    }
    last[i] = 0;
    return last;
}

char *get_next_line(int fd)
{
    static char *temp = NULL;
    int bol = 0;
    int i = 0;
    char *reading;
    char *last;

    while (temp && temp[i])
        bol += (temp[i++] == '\n');
    if (bol)
        return (my_strcpy(temp));
    if (!(reading = read_next_n_bytes(fd))) {
        (temp && (!(*temp))) ? free(temp), temp = NULL : 0;
        if (temp == NULL)
            return (NULL);
        last = strcpy_last(temp);
        temp = NULL;
        return (last);
    }
    temp = concat(temp, reading);
    free(reading);
    return (get_next_line(fd));
}