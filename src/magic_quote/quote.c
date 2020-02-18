/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** quote.c
*/

#include "mysh.h"

void print_error_quote(char c)
{
    write(1, "Unmatched '", 11);
    write(1, &c, 1);
    write(1, "'.\n", 3);
}

char *check_char(char *cmd, int index, char type)
{
    int j = index + 1;

    while (cmd[j]) {
        if (cmd[j] == type)
            return (cmd);
        j++;
    }
    print_error_quote(type);
    return (NULL);
}

int len_quotes(char const *cmd, int index, char type)
{
    int len = index + 1;

    while (cmd[len]) {
        if (cmd[len] == type)
            return (len);
        len++;
    }
    return (len);
}

char *quote_manager(char *cmd, infos *info)
{
    char *temp = my_strdup(cmd);

    for (int i = 0; cmd && cmd[i]; i++) {
        if (cmd[i] == 34 || cmd[i] == 39 || cmd[i] == 96) {
            if ((cmd = check_char(cmd, i, cmd[i])) == NULL)
                return (NULL);
            if (cmd[i] == 96)
                temp = backticks(cmd, info, i);
            i = len_quotes(cmd, i, cmd[i]);
        }
    }
    if (cmd)
        free(cmd);
    return (temp);
}