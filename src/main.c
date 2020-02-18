/*
** EPITECH PROJECT, 2019
** main
** File description:
** executes main
*/

#include "mysh.h"

infos *init_env(char **env)
{
    infos *inf = malloc(sizeof(infos));
    size_t size = 1000;

    inf->len = 0;
    if (env && *env) {
        for (int i = 0; env[i]; i++)
            env_in_list(inf, env[i]);
        free(inf->last->next);
        inf->last->next = NULL;
    } else {
        inf->last = NULL;
    }
    inf->local_var = NULL;
    if (env && *env)
        found_path(inf);
    inf->oldpwd = NULL;
    inf->pwd = malloc(sizeof(char) * 1000);
    getcwd(inf->pwd, size);
    inf->alias = NULL;
    return (inf);
}

int main(int ac, char **av, char **env)
{
    infos *inf = init_env(env);
    int i = 0;
    int j = 0;

    signal(SIGINT, SIG_IGN);
    inf->indexpipe = malloc(sizeof(int) * 1);
    1 ? inf->exit = 0, inf->pipelist = NULL : 0;
    inf->index = malloc(sizeof(int) * 1);
    inf->index2 = malloc(sizeof(int) * 1);
    if (env && *env) {
        for (i = 0; env[i]; i++);
        inf->env = malloc(sizeof(char *) * i + 8);
        for (j = 0; env[j]; j++)
            inf->env[j] = my_strdup(env[j]);
        1 ? inf->env[j] = NULL, get_home(inf) : 0;
    } else {
        inf = building_own_env(inf);
    }
    check_path(inf);
    minishell(inf);
    return (0);
}
