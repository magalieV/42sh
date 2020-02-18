/*
** EPITECH PROJECT, 2019
** how_many_char
** File description:
** counts how many char
*/

#include "mysh.h"

int how_many_simple(char const *str, char c)
{
    int res = 0;
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i]) {
        if (str[i] == c && str[i + 1] != c)
            res++;
        i++;
    }
    return (res);
}

int how_many_char(char const *str, char c)
{
    int res = 0;
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i]) {
        if (str[i] == c)
            res++;
        i++;
    }
    return (res);
}