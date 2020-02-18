/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** cd_gestion.c
*/

#include "mysh.h"

void check_env(infos *inf, char *to_get, char *value)
{
    element *e = inf->first;
    char **tab = malloc(sizeof(char *) * 4);

    tab[0] = my_strdup("setenv");
    tab[1] = to_get;
    tab[2] = value;
    tab[3] = NULL;
    while (e != NULL && my_strcmp(e->var, to_get) != 0)
        e = e->next;
    if (e == NULL)
        cmd_setenv(tab, inf);
    else {
        e->value = my_strdup(value);
    }
}

int check_error(char *file_path, infos *inf, char **cmd)
{
    struct stat filestat;

    stat(file_path, &filestat);
    if (access(file_path, F_OK) == -1) {
        fprintf(stderr, "%s: No such file or directory.\n", cmd[1]);
        return (1);
    } if (S_ISDIR(filestat.st_mode) == 0) {
        fprintf(stderr, "%s: Not a directory.\n", cmd[1]);
        return (1);
    } if (access(file_path, X_OK) == -1) {
        fprintf(stderr, "%s: Permission denied.\n", file_path);
        return (1);
    }
    return (0);
}

int change_pwd(infos *inf, char *direction)
{
    size_t size = 1000;

    inf->oldpwd = my_strdup(inf->pwd);
    chdir(direction);
    getcwd(inf->pwd, size);
    check_env(inf, "PWD", inf->pwd);
    check_env(inf, "OLDPWD", inf->oldpwd);

    return (0);
}

int cd_main(char **cmd, infos *inf)
{
    bool found = false;

    if (my_strlen(cmd[1]) == 1 && cmd[1][0] == '-') {
        if (inf->oldpwd == NULL) {
            write(2, ": No such file or directory.\n", 29);
            inf->exit = 1;
        } else {
            change_pwd(inf, inf->oldpwd);
        }
        found = true;
    } else if (my_tablen(cmd) > 1
    && (inf->exit = check_error(cmd[1], inf, cmd)) == 0) {
        change_pwd(inf, cmd[1]);
        found = true;
    }
    if (!found && my_tablen(cmd) == 1)
        change_pwd(inf, inf->home);
    return (inf->exit);
}

int cmd_cd(char **cmd, infos *inf)
{
    if (how_many_this(cmd, "|\0") != 0) {
        pipes(cmd, inf);
        if (inf->pipelist)
            free_pipecmd(inf->pipelist);
        inf->pipelist = NULL;
        return (inf->exit);
    }
    if (my_tablen(cmd) > 2) {
        fprintf(stderr, "%s: Too many arguments.\n", cmd[0]);
        return (84);
    } else
        inf->exit = cd_main(cmd, inf);
    return (inf->exit);
}