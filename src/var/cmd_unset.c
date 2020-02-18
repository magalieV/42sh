/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** TODO: add description
*/

#include "mysh.h"

int cmd_unset(char **cmd, infos *inf)
{
    if (my_tablen(cmd) < 2) {
        fprintf(stderr, "unset: Too few arguments.\n");
        return (1);
    }
    for (int i = 1; cmd[i]; ++i) {
        if (get_local(inf, cmd[i]) && dlist_length(inf->local_var) != 1) {
            pop_at_index(&inf->local_var, i - 1);
        } else
            pop_back(&inf->local_var);
    }
    return (0);
}