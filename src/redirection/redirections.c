/*
** EPITECH PROJECT, 2019
** redirections.c
** File description:
** functions for redirections
*/

#include "mysh.h"

int redirections(char **cmd, infos *env)
{
    return (execute_cdm(env, cmd, true));
}

char *recup_path(char **str, char *param)
{
    char *cmd = NULL;
    bool bolean = false;

    if (!str)
        return (NULL);
    for (int i = 0; str[i]; i++) {
        if (my_strcmp(str[i], param) == 0 && str[i + 1]) {
            bolean = true;
        }
        if (bolean) {
            cmd ? free(cmd) : 0;
            cmd = my_strdup(str[i + 1]);
            bolean = false;
        }
    }
    return (cmd);
}

char **remove_end_cmd(char **str)
{
    bool bolean = false;
    char **string = malloc(sizeof(char *) * my_tablen(str));
    int k = 0;

    if (!str)
        return (NULL);
    for (int i = 0; str[i]; i++) {
        if ((my_strcmp(str[i], ">") == 0 || my_strcmp(str[i], "<") == 0
        || my_strcmp(str[i], ">>") == 0 || my_strcmp(str[i], "<<") == 0)) {
            bolean = true;
        }
        if (!bolean)
            string[k++] = my_strdup(str[i]);
    }
    string[k] = 0;
    return (string);
}