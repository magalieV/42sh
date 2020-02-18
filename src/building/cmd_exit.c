/*
** EPITECH PROJECT, 2019
** cmd_exit
** File description:
** exit
*/

#include "mysh.h"

int check_exit(char *cmd)
{
    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] < 48 || cmd[i] > 57)
            return (1);
    }
    return (0);
}

int my_exit(char **cmd, infos *inf)
{
    int s = 0;

    if (my_tablen(cmd) == 1) {
        free_my_tab(cmd);
        free_my_env(inf);
        my_putstr("exit\n");
        exit(0);
    }
    if (my_tablen(cmd) == 2) {
        if (check_exit(cmd[1]) == 0) {
            s = my_getnbr(cmd[1]);
            free_my_tab(cmd);
            free_my_env(inf);
            my_putstr("exit\n");
            exit(s);
        }
    }
    my_putstr("exit: Invalid syntax.\n");
    return (0);
}

int cmd_exit(char **cmd, infos *inf)
{
    int *ret = malloc(sizeof(int) * 1);

    *ret = inf->exit;
    if (how_many_this(cmd, "|\0") != 0) {
        pipes(cmd, inf);
        if (inf->pipelist)
            free_pipecmd(inf->pipelist);
        inf->pipelist = NULL;
        return (inf->exit);
    }
    if (cmd[0] == NULL) {
        free_my_tab(cmd);
        free_my_env(inf);
        if (isatty(0) != 0)
            my_putstr("exit\n");
        exit(*ret);
    }
    else
        my_exit(cmd, inf);
    return (0);
}
