/*
** EPITECH PROJECT, 2018
** double_redirections
** File description:
** Implementation of double_redirections
*/

#include "mysh.h"

bool redirection_double_right(infos *env, char **cmd, bool execute)
{
    int tab[2] = {0};
    int op = 0;

    tab[0] = dup(0);
    tab[1] = dup(1);
    op = open_all_file((char const **)cmd, O_WRONLY | O_CREAT | O_APPEND);
    dup2(op, STDOUT_FILENO);
    execute ? cmd = remove_end_cmd(cmd) : 0;
    execute ? found_my_cmd(cmd, env) : 0;
    execute ? reaffect_std(tab) : 0;
    return (true);
}

char *get_my_buffer(char **cmd)
{
    char *path = recup_path(cmd, "<<");
    char *temp = NULL;
    char *buffer = malloc(sizeof(char)* 1);

    buffer[0] = '\0';
    if (!path)
        return (NULL);
    while (1) {
        temp = get_next_line(0);
        if (!temp || my_strcmp(temp, path) == 0)
            break;
        buffer = my_realloc(buffer, sizeof(char) *
        (my_strlen(buffer) + my_strlen(temp)), temp);
        buffer = my_realloc(buffer, sizeof(char) *
        (my_strlen(buffer) + 2), "\n");
        free(temp);
    }
    return (buffer);
}

bool redirection_double_left(infos *env, char **cmd, bool execute)
{
    int tab[2] = {0};
    int op = 0;
    char *buffer = get_my_buffer(cmd);
    int pipefd[2] = {0};

    if (!buffer)
        return (false);
    tab[0] = dup(0);
    tab[1] = dup(1);
    pipe(pipefd);
    write(pipefd[1], buffer, my_strlen(buffer));
    close(STDIN_FILENO);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[1]);
    execute ? cmd = remove_end_cmd(cmd) : 0;
    execute ? found_my_cmd(cmd, env) : 0;
    execute ? reaffect_std(tab) : 0;
    return (true);
}

bool multi_redirect_right(char **cmd, infos *env, bool bolean)
{
    bool found = false;

    if (search_param(cmd, ">>")) {
        found = true;
        redirection_double_right(env, cmd, bolean);
    } else if (search_param(cmd, ">")) {
        execute_simple_redirection(env, cmd, 1, bolean);
        found = true;
    }
    found = (multi_redirect_double(cmd, env) == true) ? true : found;
    return (found);
}

bool multi_redirect(char **cmd, infos *env)
{
    int tab[2] = {0};
    bool found = false;
    int size = count_redirect(cmd);
    bool bolean = false;

    tab[0] = dup(STDOUT_FILENO);
    tab[1] = dup(STDIN_FILENO);
    if (size == 0) {
        cmd = decoup_redirect(cmd);
        size = count_redirect(cmd);
        if (size > 0)
            cmd = convert_cmd(cmd);
    }
    if (size == 0)
        return (false);
    if (size > 3)
        return (error_redirect());
    (size == 1) ? bolean = true : 0;
    found = multi_redirect_right(cmd, env, bolean);
    reaffect_std(tab);
    return (found);
}