/*
** EPITECH PROJECT, 2019
** epuration
** File description:
** contains all epurations
*/

#include "mysh.h"

int how_many_words_suit(char const *str, int j)
{
    bool found = false;

    if (str[j] == 39) {
        j = len_quotes(str, j, 39) + 1;
        found = true;
    } else if (str[j] == 34) {
        j = len_quotes(str, j, 34) + 1;
        found = true;
    }
    while (!found && bool_char(str[j]) == 1)
        j += 1;
    return (j);
}

char **remove_first_cmd(char **cmd)
{
    int len = my_tablen(cmd);
    char **new_string = NULL;
    int k = 0;

    if (len <= 1 || ((new_string = malloc(sizeof(char *) * (len + 1))) == NULL))
        return (cmd);
    for (int i = 1; cmd[i]; i++) {
        new_string[k++] = my_strdup(cmd[i]);
    }
    new_string[k] = 0;
    return (new_string);
}

char *epurvar(char const *var)
{
    int i = 0;
    int j = 0;
    char *result;

    for (i = 0; var[i] != '='; i++);
    if ((result = malloc(sizeof(char) * i + 1)) == NULL)
        return (NULL);
    while (j < i) {
        result[j] = var[j];
        j++;
    }
    result[j] = '\0';
    return (result);
}

char *epurvalue(char const *var)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *result;

    for (i = 0; var[i]; i++);
    for (k = 0; var[k] != '='; k++);
    k++;
    if ((result = malloc(sizeof(char) * i - k + 1)) == NULL)
        return (NULL);
    while (var[k]) {
        result[j] = var[k];
        j++;
        k++;
    }
    result[j] = '\0';
    return (result);
}
