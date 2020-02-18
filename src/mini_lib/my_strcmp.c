/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compares two strings
*/

#include "mysh.h"

int my_tabcmp(char **tab_one, char **tab_two)
{
    int len_one = my_tablen(tab_one);
    int len_two = my_tablen(tab_two);

    if (len_one != len_two || len_one <= 0)
        return (1);
    for (int i = 0; tab_one[i]; i++) {
        if (my_strcmp(tab_one[i], tab_two[i]) != 0)
            return (1);
    }
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1 && s2 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i != n - 1)
        i++;
    return (s1[i] - s2[i]);
}
