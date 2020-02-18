/*
** EPITECH PROJECT, 2019
** backticks
** File description:
** functions for backticks
*/

#include "mysh.h"

char *get_cmd(char *cmd)
{
    FILE *fp;
    char *test = "echo '", *test2 = "' | ./42sh", *test3 = NULL, \
    *result = my_strdup("\0");
    char buffer[32];
    int it = 0;

    test3 = my_strcat_wof(my_strdup(test), cmd);
    test3 = my_strcat_wof(test3, my_strdup(test2));
    fp = popen(test3, "r");
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (it == 0)
            result = my_strdup(buffer);
        else
            result = my_strcat_wof(result, buffer);
        1 ? result[my_strlen(result) - 1] = ' ', it++ : 0;
    }
    if (my_strlen(result) == 0)
        return (NULL);
    result[my_strlen(result) - 1] = '\0';
    pclose(fp);
    return (result);
}

char *remove_bacticks(char const *cmd, char *result, int index)
{
    char *first_part = NULL, *last_part = NULL, *res = NULL;
    int a = 0, b = 0, c = 0, d = 0, e = 0;

    for (a = 0; a != index; a++);
    first_part = malloc(sizeof(char) * a);
    for (int t = 0; t != index; t++) {
        first_part[b] = cmd[t];
        b++;
    }
    first_part[b] = '\0';
    for (c = a + 1; cmd[c] != '`'; c++);
    for (d = c + 1; cmd[d]; d++);
    last_part = malloc(sizeof(char) * (d - c));
    for (int t = c + 1; cmd[t]; t++) {
        last_part[e] = cmd[t];
        e++;
    }
    last_part[e] = '\0';
    res = my_strcat_wof(first_part, result);
    res = my_strcat_wof(res, last_part);
    return (res);
}

char *remove_between_backticks(char const *cmd, int index)
{
    int i = index + 1, j = 0, v = 0;
    char *newcmd = NULL;

    while (cmd[i] != '`') {
        i++;
        j++;
    }
    i++;
    newcmd = malloc(sizeof(char) * (strlen(cmd) - j) + 2);
    for (v = 0; v != index; v++)
        newcmd[v] = cmd[v];
    newcmd[v++] = ' ';
    while (cmd[i]) {
        newcmd[v] = cmd[i];
        v++;
        i++;
    }
    newcmd[v] = '\0';
    return (newcmd);
}

char *backticks(char const *cmd, infos *inf, int i)
{
    char *res = NULL, *newcmd = NULL, *backtick = NULL;
    int j = 0, v = 0;

    while (cmd[j + i + 1] != '`')
        j++;
    newcmd = malloc(sizeof(char) * j + 1);
    for (int k = i + 1; cmd[k] != '`'; k++) {
        newcmd[v] = cmd[k];
        v++;
    }
    newcmd[v] = '\0';
    backtick = get_cmd(newcmd);
    if (backtick == NULL)
        res = remove_between_backticks(cmd, i);
    else {
        res = remove_bacticks(cmd, backtick, i);
        free(backtick);
    }
    free(newcmd);
    return (res);
}