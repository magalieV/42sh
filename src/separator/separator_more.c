/*
** EPITECH PROJECT, 2019
** separator_more.
** File description:
** Implementation of separator_more
*/

#include "mysh.h"

int how_many_this(char **cmd, char *c)
{
    int res = 0;

    if (cmd[0] == NULL)
        return (0);
    for (int i = 0; cmd[i]; i++) {
        if (my_strcmp(cmd[i], c) == 0)
            res += 1;
    }
    return (res);
}

char **cut_my_cmd(char **cmd, char *sep, int *index)
{
    char **newcmd = NULL;
    int k = *index;
    int j = 0;

    for (; cmd[*index] && my_strcmp(cmd[*index], sep) != 0; *index += 1);
    newcmd = malloc(sizeof(char *) * (*index - k) + 8);
    for (j = 0; j < *index - k; j++)
        newcmd[j] = my_strdup(cmd[k + j]);
    newcmd[j] = NULL;
    *index += 1;
    return (newcmd);
}