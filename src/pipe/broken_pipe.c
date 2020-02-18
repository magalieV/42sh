/*
** EPITECH PROJECT, 2019
** broken pipes
** File description:
** error handling for pipes
*/

#include "mysh.h"

int broken_pipe(pipecmd *index, pipecmd *indexprev)
{
    if (indexprev && index && index->cmd[0] == NULL) {
        if (my_strcmp(indexprev->cmd[0], "cd") != 0)
            fprintf(stderr, "%s: write error: Broken pipe\n", \
            indexprev->cmd[0]);
        return (-1);
    }
    return (0);
}

int check_for_pipecd(infos *inf)
{
    pipecmd *index = inf->pipelist;

    while (index && index->next)
        index = index->next;
    if (index && index->cmd[0] && (my_strcmp(index->cmd[0], "cd") == 0
        || my_strcmp(index->cmd[0], "setenv") == 0
        || my_strcmp(index->cmd[0], "unsetenv") == 0)) {
        inf->exit = \
        cmd_ptr[found_cmd(index->cmd, index->cmd)](index->cmd, inf);
        if (my_strcmp(index->cmd[0], "cd") == 0 && inf->exit == 0) {
            my_putstr("(wd now: ");
            my_putstr(index->cmd[1]);
            my_putstr(")\n");
        }
    }
    return (inf->exit);
}