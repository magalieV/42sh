/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** __DESCRIPTION__
*/

#include "my_sh_hd.h"

int if_alphnum_up(char const *str, int i, char *param)
{
    if (!str[i])
        return (0);
    for (int j = 0; param[j]; j++) {
        if (param[j] == str[i])
            return (0);
    }
    return (1);
}

int alloc_memo_up(char const *str, char *param)
{
    int i = 0;
    int k = 0;

    while (str[i]) {
        if (if_alphnum_up(str, i, param) && !if_alphnum_up(str, i + 1, param))
            k++;
        i++;
    }
    return (k);
}

char **my_str_to_word_array_up(char const *str, char *param)
{
    char **dest;
    int i = 0;
    int g = 0;
    int n;

    dest = malloc(sizeof(char *) * (alloc_memo_up(str, param) + 1) + 1);
    while (str[g]) {
        if (!if_alphnum_up(str, g, param))
            g++;
        for (n = g; if_alphnum_up(str, n, param); n++);
        dest[i] = (char *)malloc((n - g) + 2);
        dest[i][0] = 0;
        for (n = 0; if_alphnum_up(str, g, param); n++)
            dest[i][n] = str[g++];
        dest[i][n] = '\0';
        if (dest[i][0])
            i++;
    }
    dest[i] = 0;
    return (dest);
}
