/*
** EPITECH PROJECT, 2019
** cmd_unsetenv
** File description:
** unsetenv
*/

#include "mysh.h"

int delete_var(infos *inf, element *e)
{
    if (e == NULL)
        return (-1);
    if (e->prev == NULL)
        inf->first = e->next;
    if (e->prev != NULL)
        e->prev->next = e->next;
    if (e->next == NULL)
        inf->last = e->prev;
    if (e->next != NULL)
        e->next->prev = e->prev;
    free(e->var);
    free(e->value);
    free(e);
    return (0);
}

int my_unsetenv(char **cmd, infos *inf)
{
    int i = 1;
    element *e = inf->first;

    while (cmd[i]) {
        while (e != NULL && my_strcmp(e->var, cmd[i]) != 0)
            e = e->next;
        delete_var(inf, e);
        e = inf->first;
        i++;
        inf->len -= 1;
    }
    return (0);
}

int cmd_unsetenv(char **cmd, infos *inf)
{
    if (how_many_this(cmd, "|\0") != 0) {
        pipes(cmd, inf);
        if (inf->pipelist)
            free_pipecmd(inf->pipelist);
        inf->pipelist = NULL;
        return (inf->exit);
    }
    if (my_tablen(cmd) == 1) {
        my_putstr("unsetenv: Not enough arguments.\n");
        return (1);
    }
    if (my_tablen(cmd) != 0)
        my_unsetenv(cmd, inf);
    return (0);
}
