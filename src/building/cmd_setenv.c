/*
** EPITECH PROJECT, 2019
** cmd_setenv
** File description:
** setenv
*/

#include "mysh.h"

void check_my_list(char **cmd, infos *inf)
{
    element *e = malloc(sizeof(element));

    e->next = NULL;
    e->var = my_strdup(cmd[1]);
    e->prev = NULL;
    inf->first = e;
    inf->last = e;
    inf->first->prev = NULL;
    inf->len += 1;
    if (my_tablen(cmd) == 2)
        e->value = my_strdup("\0");
    else
        e->value = my_strdup(cmd[2]);
}

element *check_tab(char **cmd, infos *inf)
{
    element *e = inf->first;

    while (e != NULL && my_strcmp(cmd[1], e->var) != 0)
        e = e->next;
    if (e != NULL)
        inf->len += 1;
    return (e);
}

void init_e_for_setenv(char **cmd, infos *inf)
{
    element *e = malloc(sizeof(element));

    if (inf->len == 0) {
        check_my_list(cmd, inf);
        inf->len += 1;
        free(e);
        return;
    }
    e->next = NULL;
    e->var = my_strdup(cmd[1]);
    e->prev = inf->last;
    inf->last->next = e;
    inf->last = e;
    inf->last->next = NULL;
    inf->len += 1;
    if (my_tablen(cmd) == 2)
        e->value = my_strdup("\0");
    else
        e->value = my_strdup(cmd[2]);
}

void my_setenv(char **cmd, infos *inf)
{
    element *e = NULL;

    if (check_tab(cmd, inf) == NULL)
        init_e_for_setenv(cmd, inf);
    else {
        if (my_tablen(cmd) == 2) {
            e = check_tab(cmd, inf);
            free(e->value);
            e->value = my_strdup("\0");
        }
        else {
            e = check_tab(cmd, inf);
            free(e->value);
            e->value = my_strdup(cmd[2]);
        }
    }
}

int cmd_setenv(char **cmd, infos *inf)
{
    if (how_many_this(cmd, "|\0") != 0) {
        pipes(cmd, inf);
        if (inf->pipelist)
            free_pipecmd(inf->pipelist);
        inf->pipelist = NULL;
        return (inf->exit);
    }
    if (my_tablen(cmd) >= 2 && check_arg(cmd[1]) == -1)
        return (84);
    if (my_tablen(cmd) == 1) {
        cmd_env(cmd, inf);
        return (0);
    }
    if (my_tablen(cmd) > 3) {
        my_putstr("setenv: Too much arguments.\n");
        return (84);
    }
    my_setenv(cmd, inf);
    modify_path(inf, cmd);
    return (0);
}
