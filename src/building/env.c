/*
** EPITECH PROJECT, 2019
** env
** File description:
** env
*/

#include "mysh.h"

int check_path(infos *infos)
{
    int i = 0;

    if (!infos->path || !*infos->path)
        return (0);
    while (infos->path && infos->path[i]) {
        if (my_strcmp(infos->path[i], "/") == 0) {
            infos->path = remove_n_line_on_tab(infos->path, i);
            i--;
        }
        i++;
    }
    if (i <= 0)
        infos->path = NULL;
    return (0);
}

int cmd_env(char **cmd, infos *inf)
{
    element *e = inf->first;

    if (how_many_this(cmd, "|\0") != 0) {
        pipes(cmd, inf);
        if (inf->pipelist)
            free_pipecmd(inf->pipelist);
        inf->pipelist = NULL;
        return (inf->exit);
    }
    while (e != NULL) {
        my_putstr(e->var);
        write(1, "=", 1);
        my_putstr(e->value);
        write(1, "\n", 1);
        e = e->next;
    }
    return (0);
}
