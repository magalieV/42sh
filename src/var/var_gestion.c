/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** TODO: add description
*/

#include "mysh.h"

char *get_env(infos *inf, char *to_get);

bool remplace_var(char ***cmd, infos *inf, int i)
{
    char *tmp = NULL;

    tmp = get_env(inf, &(*cmd)[i][1]);
    if (!tmp)
        tmp = get_local(inf, &(*cmd)[i][1]);
    if (!tmp) {
        write(2, &(*cmd)[i][1], strlen(&(*cmd)[i][1]));
        write(2, ": Undefined variable.\n", 23);
        return (false);
    }
    (*cmd)[i] = my_strdup(tmp);
    return (true);
}

bool cmd_var(char ***cmd, infos *inf)
{
    bool value = true;

    for (int i = 0; (*cmd)[i]; ++i) {
        if (!value)
            return (value);
        if ((*cmd)[i][0] == '$' && (*cmd)[i][1])
            value = remplace_var(cmd, inf, i);
    }
    return (value);
}