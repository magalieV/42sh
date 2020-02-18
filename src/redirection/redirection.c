/*
** EPITECH PROJECT, 2018
** redirection
** File description:
** Implementation of redirection
*/

#include "mysh.h"

ptr_cmd_t PTR_CDM[] = {
    {"cd", &cmd_cd},
    {"setenv", &cmd_setenv},
    {"unsetvenv", &cmd_unsetenv},
    {"env", &cmd_env},
    {"exit", &cmd_exit},
    {"!", &cmd_history},
    {"history", &cmd_history},
    {"repeat", &cmd_repeat},
    {"set", &cmd_set},
    {"unset", &cmd_unset},
    {"which", &cmd_which},
    {"where", &cmd_where},
    {"echo", &cmd_echo},
    {"alias", &cmd_alias},
    {"unalias", &cmd_unalias},
    {NULL, NULL},
};

int found_my_cmd(char **str, infos *info)
{
    if (!str)
        return (-1);
    for (int i = 0; PTR_CDM[i].cmd; i++) {
        if (my_strcmp(PTR_CDM[i].cmd, str[0]) == 0) {
            PTR_CDM[i].sort(str, info);
            return (0);
        }
    }
    no_cmd(str, info);
    return (1);
}

int open_all_file(char const **str, int flags)
{
    bool bolean = false;
    bool after = false;
    int op = 0;
    char *save = NULL;

    for (int i = 0; str[i]; i++) {
        if (my_strcmp(str[i], ">") == 0 || my_strcmp(str[i], ">>") == 0)
            bolean = true;
        if (bolean && after) {
            op = open(str[i], flags, 0755);
            op != -1 ? close(op) : 0;
            bolean = false;
            after = false;
            save ? free(save) : 0;
            save = my_strdup(str[i]);
        } else if (bolean && !after) {
            after = true;
        }
    }
    op = open(save, flags);
    return (op);
}

bool create_file(int nb, char const *path, char const **cmd)
{
    int op = 0;

    if (!nb && (op = open(path, O_RDONLY)) == -1) {
        my_perror(path);
        my_putstr(": No such file or directory.\n");
        return (true);
    } else {
        close(STDIN_FILENO);
        dup2(op, STDIN_FILENO);
    }
    if (nb) {
        op = open_all_file(cmd, O_WRONLY | O_CREAT | O_TRUNC);
        close(STDOUT_FILENO);
        dup2(op, STDOUT_FILENO);
    }
    return (false);
}

bool reaffect_std(int tab[2])
{
    if (!tab) {
        return (false);
    }
    dup2(tab[0], STDOUT_FILENO);
    dup2(tab[1], STDIN_FILENO);
    return (true);
}

bool execute_simple_redirection(infos *env, char **str, int nb, bool execute)
{
    char *path = NULL;
    int tab[2] = {0};

    tab[0] = dup(0);
    tab[1] = dup(1);
    if (nb == 0 && ((path = recup_path(str, "<")) == NULL))
        return (false);
    if (create_file(nb, path, (char const **)str))
        return (true);
    execute ? str = remove_end_cmd(str) : 0;
    execute ? found_my_cmd(str, env) : 0;
    execute ? reaffect_std(tab) : 0;
    return (true);
}