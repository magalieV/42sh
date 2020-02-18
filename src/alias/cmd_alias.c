/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "mysh.h"

int print_alias_value(infos *inf, char *name)
{
    node_t *temp = NULL;

    if (inf->alias) {
        for (temp = inf->alias->begin; temp; temp = temp->next) {
            if (my_strcmp(name, temp->data->name) == 0) {
                my_putstr(temp->data->value);
                write(1, "\n", 1);
            }
        }
    }
}

void print_alias(dlist_t *list)
{
    node_t *tmp = NULL;

    if (list == NULL)
        return;
    else
        tmp = list->begin;
    for (; tmp; tmp = tmp->next) {
        if (tmp->data->bol == 0) {
            my_putstr(tmp->data->name);
            print_spaces(strlen(tmp->data->name) % 8);
            if (tmp->data->value)
                my_putstr(tmp->data->value);
            my_putstr("\n");
        }
    }
}

char *test(char **cmd, infos *inf)
{
    char *str = NULL;

    for (int i = 2; cmd[i]; i++) {
        str = (char *)my_strcat_properly(str, my_strdup(cmd[i]));
        str = (char *)my_strcat_properly(str, my_strdup(" "));
    }
    return (str);
}

int add_alias(char **cmd, infos *inf)
{
    node_t *temp = NULL;
    int bol = 0;

    if (inf->alias != NULL) {
        for (temp = inf->alias->begin; temp; temp = temp->next) {
            if (my_strcmp(cmd[1], temp->data->name) == 0
                && temp->data->bol == 0) {
                temp->data->value = test(cmd, inf);
                bol = 1;
            }
        }
        if (bol == 0) {
            push_back(&inf->alias, init_data_bis(cmd[1], test(cmd, inf), 0));
        }
    } else
        push_back(&inf->alias, init_data_bis(cmd[1], test(cmd, inf), 0));

}

int cmd_alias(char **cmd, infos *inf)
{
    if (my_tablen(cmd) == 1)
        print_alias(inf->alias);
    else if (my_tablen(cmd) == 2)
        print_alias_value(inf, cmd[1]);
    else
        add_alias(cmd, inf);
    return (0);
}