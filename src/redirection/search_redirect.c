/*
** EPITECH PROJECT, 2018
** search_redirect
** File description:
** Implementation of search_redirect
*/

#include "mysh.h"

char *pars_my_cmd(char *str, int *n, char *string, char *tmp)
{
    int i = *n;

    if (str[i] == '\\' && str[i + 1] && str[i + 1] == ' ' && str[i + 2]
        && str[i + 2] != ' ') {
        1 ? string = modify_cmd(str, string), i++ : 0;
    } else if (str[i] == '\\' && str[i + 1] && (str[i + 1] == ' '
    || str[i + 1] == '\\')) {
        (str[i + 1] && str[i + 1] == '\\') ? string = my_realloc(string,
            sizeof(char) * (my_strlen(string) + 1), "\\") : 0;
        (str[i + 1] && str[i + 1] == ' ') ? string = my_realloc(string,
            sizeof(char) * (my_strlen(string) + 3), "\\\\ ") : 0;
        i += (count_number_slach(str, i) - 1);
    } else {
        1 ? tmp[0] = str[i], string = my_realloc(string, sizeof(char) *
        (my_strlen(string) + 2), tmp) : 0;
    }
    *n = i;
    return (string);
}

char **decoup_redirect(char **cmd)
{
    char **new_cmd = malloc(sizeof(char *) * (my_tablen(cmd) * 2));
    int k = 0;

    for (int i = 0; cmd[i]; i++) {
        new_cmd = copy_my_arg(cmd, new_cmd, i, &k);
    }
    return (new_cmd);
}

bool error_redirect(void)
{
    my_perror("Ambiguous output redirect.\n");
    return (true);
}

int count_redirect(char **str)
{
    int count = 0;

    if (search_param(str, ">>"))
        count++;
    if (search_param(str, ">"))
        count++;
    if (search_param(str, "<<"))
        count++;
    if (search_param(str, "<"))
        count++;
    return (count);
}

bool search_param(char **str, char *param)
{
    if (!str || !*str)
        return (false);
    for (int i = 0; str[i]; i++) {
        if (my_strcmp(str[i], param) == 0)
            return (true);
    }
    return (false);
}
