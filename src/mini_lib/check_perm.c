/*
** EPITECH PROJECT, 2019
** check_perm
** File description:
** check permission
*/

#include "mysh.h"

int check_perm(char **cmd)
{
    if (my_tablen(cmd) > 1 && access(cmd[1], X_OK) == -1
        && my_strcmp(cmd[1], "-") != 0 && my_strcmp(cmd[1], "--") != 0) {
        my_putstr(cmd[1]);
        my_putstr(": ");
        my_perror("Permission denied.\n");
        return (84);
    }
    return (0);
}
