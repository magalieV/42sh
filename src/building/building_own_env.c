/*
** EPITECH PROJECT, 2019
** building_own_env.
** File description:
** Implementation of building_own_env
*/

#include "mysh.h"

char const *own_env[] = {
    "/usr/local/bin",
    "/usr/local/bin",
    "/usr/sbin",
    "/usr/bin",
    "/sbin",
    "/bin",
    "/usr/games",
    "/usr/local/games",
    "/snap/bin",
    NULL,
};

void env_in_list(infos *inf, char *var)
{
    element *e = malloc(sizeof(element));

    e->next = NULL;
    e->value = epurvalue(var);
    e->var = epurvar(var);
    if (inf->len == 0) {
        e->prev = NULL;
        inf->first = e;
        inf->last = e;
        inf->len += 1;
        return;
    }
    inf->len += 1;
    e->prev = inf->last;
    inf->last->next = e;
    inf->last = e;
}

void found_path(infos *inf)
{
    element *e = inf->first;

    while (e != NULL && my_strcmp(e->var, "PATH") != 0) {
        e = e->next;
    }
    if (e == NULL) {
        inf->path = my_tab_dup((char **) own_env);
    } else
        inf->path = my_str_to_word_array(e->value);
}

infos *building_own_env(infos *infos)
{
    char *buffer = malloc(sizeof(char) * PATH_MAX);

    infos->path = my_tab_dup((char **)own_env);
    infos->home = my_strdup("~/");
    buffer = getcwd(buffer, PATH_MAX);
    infos->env = malloc(sizeof(char *) * 3);
    infos->env[0] = malloc(sizeof(char) * 1);
    infos->env[0][0] = '\0';
    infos->env[0] = my_realloc(infos->env[0], sizeof(char) *
    (my_strlen(infos->env[0]) + 4), "PWD=");
    infos->env[0] = my_realloc(infos->env[0], sizeof(char) *
    (my_strlen(infos->env[0]) + my_strlen(buffer)), buffer);
    infos->env[1] = my_realloc(infos->env[1], sizeof(char) *
    (my_strlen(infos->env[1]) + 5), "HOME=");
    infos->env[1] = my_realloc(infos->env[1], sizeof(char) *
    (my_strlen(infos->env[1]) + my_strlen(infos->home)), infos->home);
    1 ? infos->env[2] = 0, free(buffer) : 0;
    for (int i = 0; infos->env[i]; i++)
        env_in_list(infos, infos->env[i]);
    1 ? free(infos->last->next), infos->last->next = NULL : 0;
    return (infos);
}