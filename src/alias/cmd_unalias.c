/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** unalias.c
*/

#include "mysh.h"

int remove_alias_bis(char **cmd, infos *inf, int i)
{
    int count = 0;
    node_t *temp = NULL;

    for (temp = inf->alias->begin; temp; temp = temp->next, count++) {
        if (my_strcmp(cmd[i], temp->data->name) == 0
            && temp->data->bol == 0)
            pop_at_index(&inf->alias, count);
    }
}

int remove_alias(char **cmd, infos *inf)
{
    for (int i = 1; cmd[i]; i++) {
        if (inf->alias != NULL) {
            remove_alias_bis(cmd, inf, i);
        }
    }
    return (0);
}

int cmd_unalias(char **cmd, infos *inf)
{
    if (my_tablen(cmd) == 1) {
        my_putstr(cmd[0]);
        my_putstr(": Too few arguments.\n");
        return (84);
    }
    else
        remove_alias(cmd, inf);
}