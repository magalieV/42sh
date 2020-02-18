/*
** EPITECH PROJECT, 2019
** change_my_value
** File description:
** readjust the env
*/

#include "mysh.h"

element *found_my_var(char *str, infos *inf)
{
    element *e = inf->first;

    if (inf->len == 0)
        return (NULL);
    while (e != NULL && my_strcmp(e->var, str) != 0)
        e = e->next;
    return (e);
}

int change_my_value(infos *inf)
{
    element *e = NULL;
    char *value = NULL;

    e = found_my_var("PWD", inf);
    if (e == NULL)
        return (84);
    value = my_strdup(e->value);
    e->value = getcwd(NULL, 0);
    e = found_my_var("OLDPWD", inf);
    if (e == NULL)
        return (84);
    e->value = my_strdup(value);
    value ? free(value) : 0;
    return (0);
}
