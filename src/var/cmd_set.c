/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** TODO: add description
*/

#include "mysh.h"

char *change_var_value(dlist_t **local_var, char *to_get, char *to_fill)
{
    node_t *tmp = (*local_var)->begin;
    int len = strlen(to_get);

    while (tmp != NULL && strncmp(tmp->data->name, to_get, len) != 0)
        tmp = tmp->next;
    if (tmp == NULL)
        return (NULL);
    else
        tmp->data->value = my_strdup(to_fill);
    return (0);
}

void print_spaces(int count)
{
    for (int i = 0; i < 8 - (count % 8); ++i)
        my_putstr(" ");
}

void print_local(dlist_t *list)
{
    node_t *tmp = NULL;

    if (list == NULL)
        return;
    else
        tmp = list->begin;
    for (; tmp; tmp = tmp->next) {
        my_putstr(tmp->data->name);
        print_spaces(strlen(tmp->data->name) % 8);
        if (tmp->data->value)
            my_putstr(tmp->data->value);
        my_putstr("\n");
    }
}

int cmd_set(char **cmd, infos *inf)
{
    char *val = NULL;
    char *var = NULL;

    if (my_tablen(cmd) == 1) {
        print_local(inf->local_var);
        return (0);
    }
    if (my_tablen(cmd) == 2 && strchr(cmd[1], '=') == 0) {
        push_back(&inf->local_var, init_data(cmd[1], "\0"));
        return (0);
    }
    for (int i = 1; cmd[i]; ++i) {
        var = epurvar(cmd[i]);
        val = epurvalue(cmd[i]);
        if (!get_local(inf, var))
            push_back(&inf->local_var, init_data(var, val));
        else
            change_var_value(&inf->local_var, var, val);
    }
    return (0);
}
