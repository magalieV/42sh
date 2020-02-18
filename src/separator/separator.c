/*
** EPITECH PROJECT, 2019
** seperator.c
** File description:
** seperator ';' management
*/

#include "mysh.h"

int (*cmd_ptr[15])(char **cmd, infos *inf) =
{
    cmd_cd, cmd_setenv, cmd_unsetenv, cmd_env, cmd_exit, cmd_repeat, cmd_set,
    cmd_unset, cmd_which, cmd_where, cmd_echo, cmd_alias, cmd_unalias, no_cmd,
    cmd_history
};

static char *found_first_separator(char **cmd, int index)
{
    int i = 0;
    int res = -1;

    while (cmd[i]) {
        if (my_strcmp(cmd[i], "&&") == 0)
            res++;
        else if (my_strcmp(cmd[i], "||") == 0)
            res++;
        if (my_strcmp(cmd[i], "&&") == 0 && res == index)
            return ("&&");
        if (my_strcmp(cmd[i], "||") == 0 && res == index)
            return ("||");
        i++;
    }
    return (";");
}

static int check_for_or_and(char **cmd, infos *inf, int k)
{
    if (*inf->index2 >= my_tablen(cmd))
        return (1);
    if (inf->exit != 0
        && my_strcmp(cmd[*inf->index2 - 1], "&&") == 0
        && my_strcmp(found_first_separator(cmd, k), ";") == 0)
        return (1);
    if (inf->exit == 0
        && my_strcmp(cmd[*inf->index2 - 1], "||") == 0)
        return (1);
    if (inf->exit != 0
        && my_strcmp(cmd[*inf->index2 - 1], "&&") == 0)
        return (2);
    return (0);
}

void get_next_cmd(infos *inf, char **cmd)
{
    while (cmd[*inf->index2] && my_strcmp(cmd[*inf->index2], "||") != 0)
        *inf->index2 += 1;
    if (cmd[*inf->index2] != NULL)
        *inf->index2 += 1;
}

void or_and_or(infos *inf, char **cmd)
{
    char **tab = NULL;
    char *ph = NULL;
    int i = 0, j = 0, k = 0;

    while ((*inf->index2 <= my_tablen(cmd)) || (i < how_many_this(cmd, "&&")
            || j < how_many_this(cmd, "||"))) {
        1 ? ph = found_first_separator(cmd, k), k++ : 0;
        tab = cut_my_cmd(cmd, ph, inf->index2);
        if ((tab[0] != NULL && my_strcmp(tab[0], "repeat") == 0) \
            || !redirections(tab, inf))
            inf->exit = cmd_ptr[found_cmd(tab, cmd)](tab, inf);
        free_my_tab(tab);
        if (check_for_or_and(cmd, inf, k) == 1)
            break;
        (check_for_or_and(cmd, inf, k) == 2) ? get_next_cmd(inf, cmd), k++ : 0;
        i = (*inf->index2 > 0
                && my_strcmp(cmd[*inf->index2 - 1], "&&") == 0 ? i + 1 : i);
        j = (*inf->index2 > 0
                && my_strcmp(cmd[*inf->index2 - 1], "||") == 0 ? j + 1 : j);
    }
}