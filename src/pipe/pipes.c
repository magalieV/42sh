/*
** EPITECH PROJECT, 2019
** pipes.c
** File description:
** functions for pipes
*/

#include "mysh.h"

int move_on(int oldfd, int newfd)
{
    int i = 0;

    if (oldfd != newfd) {
        i = dup2(oldfd, newfd);
        close(oldfd);
    }
    return (i);
}

void exec_fork_pipe(pipecmd *index, int input_fd, infos *inf)
{
    pid_t pid;
    int pipfd[2] = {5, 6};

    pipe(pipfd);
    if ((pid = fork()) == 0) {
        close(pipfd[0]);
        move_on(input_fd, STDIN_FILENO);
        move_on(pipfd[1], STDOUT_FILENO);
        use_my_cmd(inf, index->cmd, inf->indexpipe);
        kill(getpid(), SIGINT);
        exit(0);
    }
    else {
        close(pipfd[1]);
        exec_pipe(index->next, pipfd[0], inf, index);
    }
}

void exec_pipe(pipecmd *index, int input_fd, infos *inf, pipecmd *indexprev)
{
    *inf->indexpipe = 0;
    if (broken_pipe(index, indexprev) == -1) {
        exec_pipe(index->next, input_fd, inf, index);
        return;
    }
    if (index->next == NULL) {
        move_on(input_fd, STDIN_FILENO);
        use_my_cmd(inf, index->cmd, inf->indexpipe);
        return;
    }
    exec_fork_pipe(index, input_fd, inf);
}

void free_pipecmd(pipecmd *p)
{
    pipecmd *index = p;
    pipecmd *index2 = p->next;

    while (index2 && index2->next) {
        free_my_tab(index->cmd);
        free(index);
        index = index2;
        index2 = index2->next;
    }
    free_my_tab(index->cmd);
    free(index);
}

void pipes(char **cmd, infos *inf)
{
    pipecmd *index = NULL;
    pid_t pid;
    int pipfd[2] = {3, 4}, stat_v = 0;

    if (check_for_pipes(cmd) == 84) {
        my_putstr("Invalid null command.\n");
        return;
    }
    inf->index3 = 0;
    inf->pipelist = malloc(sizeof(pipecmd));
    for (int i = 0; i <= how_many_this(cmd, "|\0"); i++)
        add_pipecmd(inf, cmd, i);
    index = inf->pipelist;
    if ((pid = fork()) == 0) {
        signal(SIGINT, SIG_DFL);
        exec_pipe(index, pipfd[0], inf, NULL);
        kill(getpid(), SIGINT);
    }
    else
        waitpid(pid, &stat_v, WCONTINUED);
    inf->exit = check_for_pipecd(inf);
}