/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias.c
*/

#include "mysh.h"

int char_alias(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

char *epur_alias_bis(char *str)
{
    char *name = malloc(sizeof(char) * my_strlen(str));
    char *value = malloc(sizeof(char) * my_strlen(str));
    int i = 0;
    int index = 0;

    for (i = 0; str[i] != '='; i++);
    i--;
    for (int j = i; char_alias(str[j]) == 1; j--, index++)
        name[index] = str[j];
    name[index] = '\0';
    name = my_revstr(name);
    i += 3;
    index = 0;
    for (int j = i; str[j] != 39; j++, index++)
        value[index] = str[j];
    value[index] = '\0';
    str = strcat(name, "=");
    str = strcat(str, value);
    return (str);
}

char **epur_alias(char **alias)
{
    for (int i = 0; alias[i]; i++) {
        alias[i] = epur_alias_bis(alias[i]);
    }
    return (alias);
}

char **modify_cmd_alias(char **cmd, char **value, int i)
{
    int len = my_tablen(cmd) + my_tablen(value);
    char **new_cmd = malloc(sizeof(char *) * (len + 1));
    int j = 0;

    for (int b = 0; cmd[b]; j++, b++) {
        if (j == i) {
            for (int a = 0; value[a]; a++, j++)
                new_cmd[j] = my_strdup(value[a]);
            j--;
        } else
            new_cmd[j] = my_strdup(cmd[b]);
    }
    new_cmd[j] = NULL;
    return (new_cmd);
}

char **alias_manager(char **cmd, infos *inf)
{
    char **value = NULL;

    push_back(&inf->alias, init_data_bis("test", "test", 1));
    for (int i = 0; cmd[i]; i++) {
        if (inf->alias != NULL) {
            for (node_t *temp = inf->alias->begin; temp; temp = temp->next) {
                value = str_array_quote(temp->data->value);
                if (my_strcmp(cmd[i], temp->data->name) == 0 &&
                    (i == 0 || my_strcmp(cmd[i-1], ";") == 0 ||
                    my_strcmp(cmd[i-1], "||") == 0 ||
                    my_strcmp(cmd[i-1], "&&") == 0)) {
                    cmd = modify_cmd_alias(cmd, value, i);
                }
            }
        }
    }
    return (cmd);
}