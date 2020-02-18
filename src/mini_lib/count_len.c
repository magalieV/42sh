/*
** EPITECH PROJECT, 2019
** my_tablen
** File description:
** returns the len of a tab
*/

#include "mysh.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str && str[i]) {
        i++;
    }
    return (i);
}

int my_tablen(char **tab)
{
    int i = 0;

    while (tab && tab[i])
        i++;
    return (i);
}
