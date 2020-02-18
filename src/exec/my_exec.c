/*
** EPITECH PROJECT, 2019
** my_exec
** File description:
** bootstrap
*/

#include "mysh.h"

void (*error_mgt[2])(char *, int) =
{
    error_perm, error_arc
};

char **make_my_args(char **tab)
{
    int i = 0;
    int k = 0;
    char **res;

    for (i = 0; tab[i]; i++);
    if ((res = malloc(sizeof(char *) * i + 8)) == NULL)
        return (NULL);
    for (int j = 0; tab[j]; j++) {
        if (my_strcmp(tab[j], "|") != 0)
            res[k] = my_strdup(tab[j]);
        k++;
    }
    res[k] = NULL;
    return (res);
}

void print_error(int stat_v)
{
    int sig = 0;

    if (WIFSIGNALED(stat_v)) {
        sig = WTERMSIG(stat_v);
        if (sig == 8)
            my_putstr("Floating exception");
        else if (sig == 6)
            my_putstr("Abort");
        else
            my_putstr(strsignal(sig));
        if (WCOREDUMP(stat_v))
            my_putstr(" (core dumped)");
        write(1, "\n", 1);
    }
}

int my_exec(char **cmd, char *cmdcat, infos *inf)
{
    char **argv = make_my_args(cmd);
    pid_t pid;
    int stat_v;

    if (inf->pipelist == NULL)
        pid = fork();
    if (inf->pipelist != NULL || pid == 0) {
        signal(SIGINT, SIG_DFL);
        execve(cmdcat, argv, inf->env);
        for (int i = 0; i < 2; i++)
            error_mgt[i](cmdcat, errno);
        free_my_tab(argv);
        kill(pid, SIGINT);
    }
    else {
        waitpid(pid, &stat_v, WTERMSIG(SIGINT));
        print_error(stat_v);
        return (stat_v);
    }
}
