/*
** EPITECH PROJECT, 2018
** cmd_repeat
** File description:
** Implementation of cmd_repeat
*/

#include "mysh.h"

char **remove_cmd_of_info(char **cmd)
{
    int len = my_tablen(cmd);
    char **new_string = NULL;
    int k = 0;

    if (len <= 0 || ((new_string = malloc(sizeof(char *) * (len))) == NULL))
        return (NULL);
    for (int i = 2; cmd[i]; i++) {
        new_string[k++] = cmd[i];
    }
    new_string[k] = 0;
    return (new_string);
}

int cmd_repeat(char **cmd, infos *info)
{
    int nb_repeat = 0;
    char **new_cmd = NULL;

    if (!cmd || !*cmd)
        return (0);
    nb_repeat = my_getnbr(cmd[1]);
    if (my_tablen(cmd) < 3) {
        my_perror("repeat: Too few arguments.\n");
        return (0);
    }
    new_cmd = remove_cmd_of_info(cmd);
    *info->index2 = 0;
    if (nb_repeat == 0)
        or_and_or(info, new_cmd);
    while (nb_repeat > 0) {
        nb_repeat--;
        *info->index2 = 0;
        or_and_or(info, new_cmd);
    }
    *info->index2 = my_tablen(cmd) + 1;
    return (0);
}