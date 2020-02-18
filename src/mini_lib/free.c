/*
** EPITECH PROJECT, 2019
** free
** File description:
** all functions for free
*/

#include "mysh.h"

void free_my_tab(char **tab)
{
    int i = 0;

    if (!tab)
        return;
    while (tab[i]) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void free_my_env(infos *inf)
{
    element *one = inf->first;
    element *next = NULL;

    while (one != NULL) {
        next = one->next;
        free(one->var);
        free(one->value);
        free(one);
        one = next;
    }
    free(next);
    free_my_tab(inf->path);
    free_my_tab(inf->env);
    free(inf);
}
