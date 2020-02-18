/*
** EPITECH PROJECT, 2019
** cmd_echo_suit.
** File description:
** Implementation of cmd_echo_suit
*/

#include "mysh.h"

char **remove_n_line_on_tab(char **tab, int n)
{
    int len = my_tablen(tab);
    char **new_tab = NULL;
    int k = 0;

    if (len <= 0 || ((new_tab = malloc(sizeof(char *) * (len + 1))) == NULL))
        return (NULL);
    for (int i = 0; tab[i]; i++) {
        if (i != n)
            new_tab[k++] = my_strdup(tab[i]);
    }
    new_tab[k] = 0;
    return (new_tab);
}

bool *found_if_good_option(char ***cmd, int i, bool *found_option,
    bool *options)
{
    if (!(*cmd)[i][1])
        return (options);
    for (int n = 1; (*cmd)[i][n]; n++) {
        if ((*cmd)[i][n] != 'e' && (*cmd)[i][n] != 'E'
        && (*cmd)[i][n] != 'n') {
            *found_option = false;
            break;
        }
        if ((*cmd)[i][n] == 'n')
            options[0] = true;
        else if ((*cmd)[i][n] == 'e')
            options[1] = true;
        else
            options[1] = false;
        *found_option = true;
    }
    if (*found_option)
        *cmd = remove_n_line_on_tab(*cmd, i);
    return (options);
}