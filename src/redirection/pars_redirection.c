/*
** EPITECH PROJECT, 2019
** pars_redirection.
** File description:
** Implementation of pars_redirection
*/

#include "mysh.h"

bool multi_redirect_double(char **cmd, infos *env)
{
    bool found = false;

    if (search_param(cmd, "<<")) {
        found = true;
        redirection_double_left(env, cmd, true);
    } else if (search_param(cmd, "<")) {
        found = true;
        execute_simple_redirection(env, cmd, 0, true);
    }
    return (found);
}

char **convert_cmd(char **cm)
{
    char **new = malloc(sizeof(char *) * (my_tablen(cm) * 2));
    int breaking = 0;
    int i = 0;
    int k = 0;

    while (cm && cm[i]) {
        breaking = i;
        if ((!my_strcmp(cm[i], ">>") || !my_strcmp(cm[i], ">")
        || !my_strcmp(cm[i], "<<") || !my_strcmp(cm[i], "<")) && cm[i + 1]
            && cm[i + 2])
            break;
        i++;
    }
    1 ? breaking += 2, i = breaking : 0;
    while (cm && cm[i])
        1 ? new[k++] = my_strdup(cm[i]), i++ : 0;
    i = 0;
    while (cm && cm[i] && i <= breaking)
        1 ? new[k++] = my_strdup(cm[i]), i++ : 0;
    new[k] = 0;
    return (new);
}

char **copy_my_arg(char **cmd, char **new_cmd, int i, int *k)
{
    int tmp = *k;
    int j = 0;

    if ((cmd[i][0] == '>' && cmd[i][1] && cmd[i][1] != '>')
        || (cmd[i][0] == '<' && cmd[i][1] && cmd[i][1] != '<')) {
        new_cmd[tmp++] = cmd[i][0] == '>' ? my_strdup(">") : my_strdup("<");
        new_cmd[tmp] = malloc(sizeof(char) * my_strlen(cmd[i]));
        for (j = 1; cmd[i][j]; j++)
            new_cmd[tmp][j - 1] = cmd[i][j];
        1 ? new_cmd[tmp][j - 1] = '\0', tmp++ : 0;
    } else if ((cmd[i][0] == '<' || cmd[i][0] == '>') && cmd[i][2]
        && (cmd[i][2] != '<' || cmd[i][2] != '>')) {
        new_cmd[tmp++] = cmd[i][0] == '>' ? my_strdup(">>") : my_strdup("<<");
        new_cmd[tmp] = malloc(sizeof(char) * my_strlen(cmd[i]));
        for (j = 2; cmd[i][j]; j++)
            new_cmd[tmp][j - 2] = cmd[i][j];
        1 ? new_cmd[tmp][j - 2] = '\0', tmp++ : 0;
    } else
        new_cmd[tmp++] = my_strdup(cmd[i]);
    1 ? *k = tmp, new_cmd[tmp] = 0 : 0;
    return (new_cmd);
}