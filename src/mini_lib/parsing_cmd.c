/*
** EPITECH PROJECT, 2018
** parsing_cmd
** File description:
** Implementation of parsing_cmd
*/

#include "mysh.h"

char *modify_cmd(char *str, char *string)
{
    char *tmp = malloc(sizeof(char) * 3);

    tmp[0] = '\\';
    tmp[1] = '\\';
    tmp[2] = '\0';
    string = my_realloc(string, sizeof(char) *
    (my_strlen(string) + 3), tmp);
    return (string);
}

int count_number_slach(char *str, int i)
{
    int count = 0;

    for (int j = i; str[i]; i++) {
        if (str[i] == '\\')
            count++;
    }
    return (count);
}

char *recup_cmd(char *str)
{
    char *string = malloc(sizeof(char) * 1);
    int len = my_strlen(str);
    char *tmp = malloc(sizeof(char) * 2);

    1 ? string[0] = '\0', tmp[1] = '\0' : 0;
    if (len <= 0)
        return (str);
    for (int i = 0; str[i]; i++) {
        string = pars_my_cmd(str, &i, string, tmp);
    }
    return (1 ? free(str), string : 0);
}

char *replace_double_hash(char *str)
{
    int len = my_strlen(str);
    char *string = NULL;
    int k = 0;

    if (len <= 0 || ((string = malloc(sizeof(char) * (len + 1))) == NULL))
        return (NULL);
    for (int i = 0; str[i]; i++) {
        if (str[i + 1] && str[i + 1] == '\\'
        && str[i] == '\\') {
            string[k++] = ' ';
            i += 1;
        } else
            string[k++] = str[i];
    }
    string[k] = '\0';
    free(str);
    return (string);
}

char **remove_double_backslach(char **cmd)
{
    if (!cmd)
        return (NULL);
    for (int i = 0; cmd[i]; i++) {
        for (int j = 0; cmd[i][j]; j++) {
            (cmd[i][j + 1] && cmd[i][j] == '\\' && cmd[i][j + 1] == '\\') ?
            cmd[i] = replace_double_hash(cmd[i]) : 0;
        }
    }
    return (cmd);
}