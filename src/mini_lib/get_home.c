/*
** EPITECH PROJECT, 2019
** get_home
** File description:
** get value of HOME
*/

#include "mysh.h"

void get_home(infos *inf)
{
    element *e = inf->first;

    while (e != NULL && my_strcmp(e->var, "HOME") != 0)
        e = e->next;
    if (e == NULL)
        inf->home = NULL;
    else
        inf->home = my_strdup(e->value);
}