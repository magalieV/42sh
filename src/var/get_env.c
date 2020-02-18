/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** TODO: add description
*/

#include "mysh.h"

char *get_env(infos *inf, char *to_get)
{
    element *e = inf->first;
    int len = strlen(to_get);

    while (e != NULL && strncmp(e->var, to_get, len) != 0)
        e = e->next;
    if (e == NULL)
        return (NULL);
    else
        return (my_strdup(e->value));
}

char *get_local(infos *inf, char *to_get)
{
    node_t *tmp = NULL;
    int len = strlen(to_get);

    if (inf->local_var == NULL)
        return (NULL);
    else
        tmp = inf->local_var->begin;
    while (tmp != NULL && strncmp(tmp->data->name, to_get, len) != 0)
        tmp = tmp->next;
    if (tmp == NULL)
        return (NULL);
    else
        return (my_strdup(tmp->data->value));
}
