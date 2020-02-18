/*
** EPITECH PROJECT, 2019
** no_cmd
** File description:
** no command
*/

#include "mysh.h"

char *my_strcat_wof(char *dest, char *src)
{
    char *final = NULL;
    int i;
    int j;

    for (i = 0 ; dest[i] ; i++);
    for (j = 0 ; src[j] ; j++);
    final = malloc(sizeof(char) * (i + j) + 1);
    for (i = 0 ; dest[i] ; i++)
        final[i] = dest[i];
    for (j = 0; src[j]; j++) {
        final[i] = src[j];
        i++;
    }
    final[i] = '\0';
    return (final);
}

int check_permission(char *cmd)
{
    int try;
    struct stat s;

    try = stat(cmd, &s);
    if (try == -1)
        return (-1);
    if (s.st_mode & S_IXUSR)
        return (0);
    else
        return (-1);
}

int find_name(char *path)
{
    if (access(path, X_OK) == 0 && check_permission(path) == 0)
        return (0);
    else
        return (-1);
}

int try_cmds(char **cmd, infos *inf)
{
    int i = 0;
    char *test;
    char *slash = "/";

    if ((find_name(cmd[0]) == 0 && inf->path == NULL)
        || (find_name(cmd[0]) == 0 && how_many_simple(cmd[0], '/') >= 1)) {
        inf->exit = my_exec(cmd, cmd[0], inf);
        return (-1);
    }
    if (!inf->path || !*inf->path)
        return (-2);
    for (i = 0; inf->path[i]; i++) {
        test = my_strcat_wof(inf->path[i], slash);
        test = my_strcat_wof(test, cmd[0]);
        if (find_name(test) == 0) {
            1 ? inf->exit = my_exec(cmd, test, inf), free(test) : 0;
            break;
        }
        free(test);
    }
    return (i);
}

int no_cmd(char **cmd, infos *inf)
{
    int check = 0;

    if (my_tablen(cmd) == 0 || cmd[0] == NULL || cmd[0][0] == '\0')
        return (inf->exit);
    if (how_many_this(cmd, "|\0") != 0) {
        pipes(cmd, inf);
        if (inf->pipelist)
            free_pipecmd(inf->pipelist);
        inf->pipelist = NULL;
        return (inf->exit);
    }
    check = try_cmds(cmd, inf);
    if (check == -1)
        return (inf->exit);
    if (check == -2 || inf->path[check] == NULL) {
        fprintf(stderr, "%s: Command not found.\n", cmd[0]);
        return (84);
    }
    return (inf->exit);
}
