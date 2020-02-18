/*
** EPITECH PROJECT, 2019
** prepare pipes
** File description:
** prepare pipes
*/

#include "mysh.h"

char const *my_cmd[] = {
        "env", "exit", "cd", "setenv", "unsetenv", "exit",
        "repeat", "set", "unset", "which", "where", "echo",
        NULL
};

int check_for_pipes(char **cmd)
{
    int nb = how_many_this(cmd, "|");

    if (my_strcmp(cmd[my_tablen(cmd) - 1], "|") == 0)
        return (84);
    return (0);
}

int try_cmds_for_pipe(char **cmd, infos *inf)
{
    int i = 0;
    char *test = NULL, *slash = "/";

    if (find_name(cmd[0]) == 0)
        return (0);
    for (int j = 0; cmd[j]; j++) {
        for (int k = 0; my_cmd[k]; k++)
            if (my_strcmp(cmd[j], my_cmd[k]) == 0)
                return (0);
        for (i = 0; inf->path[i]; i++) {
            test = my_strcat_wof(inf->path[i], slash);
            test = my_strcat_wof(test, cmd[j]);
            if (find_name(test) == 0)
                return (free(test), 0);
            free(test);
        }
    }
    return (-1);
}

pipecmd *prepare_my_cmd(char **cmd, infos *inf)
{
    pipecmd *newcmd = malloc(sizeof(pipecmd));
    int k = inf->index3, j = 0;

    for (; cmd[inf->index3] && my_strcmp(cmd[inf->index3], "|\0") != 0;
    inf->index3 += 1);
    newcmd->cmd = malloc(sizeof(char *) * (inf->index3 - k) + 8);
    for (j = 0; j < inf->index3 - k; j++)
        newcmd->cmd[j] = my_strdup(cmd[k + j]);
    newcmd->cmd[j] = NULL;
    inf->index3 = (inf->index3 >= my_tablen(cmd) ? 0 : inf->index3 + 1);
    if (my_strcmp(newcmd->cmd[0], "cd") != 0
        && my_strcmp(newcmd->cmd[0], "unsetenv") != 0
        && my_strcmp(newcmd->cmd[0], "setenv") != 0
        && try_cmds_for_pipe(newcmd->cmd, inf) == -1) {
        fprintf(stderr, "%s: Command not found.\n", newcmd->cmd[0]);
        free_my_tab(newcmd->cmd);
        newcmd->cmd = malloc(8);
        newcmd->cmd[0] = NULL;
    }
    return (newcmd);
}

int add_pipecmd(infos *inf, char **cmd, int var)
{
    pipecmd *nwcmd = prepare_my_cmd(cmd, inf);
    pipecmd *index = inf->pipelist;
    pipecmd *index2 = inf->pipelist;
    int i = 0;

    if (var == 0) {
        inf->pipelist = nwcmd;
        inf->pipelist->next = NULL;
        return (0);
    }
    for (i = 0; index != NULL; i++) {
        if (i > 0)
            index2 = index2->next;
        index = index->next;
    }
    index = nwcmd;
    index->next = NULL;
    index2->next = index;
    return (0);
}