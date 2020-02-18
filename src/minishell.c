/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** displays a terminal
*/

#include "mysh.h"

int modify_path(infos *infos, char **cmd)
{
    char **new_path = NULL;

    if (my_strcmp(cmd[1], "PATH") == 0) {
        free_my_tab(infos->path);
        if (cmd[2]) {
            new_path = my_str_to_word_array(cmd[2]);
            infos->path = my_tab_dup(new_path);
            free_my_tab(new_path);
        } else
            infos->path = NULL;
    }
    check_path(infos);
    return (0);
}

int found_cmd(char **cmd, char **truecmd)
{
    int i = 0;
    char *system[15] = {"cd", "setenv", "unsetenv", "env", "exit", "repeat",
    "set", "unset", "which", "where", "echo", "alias", "unalias", NULL};

    if (cmd[0] == NULL && my_tablen(truecmd) == 0)
        return (4);
    if (cmd[0] == NULL && my_tablen(truecmd) != 0)
        return (13);
    while (system[i] && my_strcmp(cmd[0], system[i]) != 0) {
        i++;
    }
    if (my_strcmp(cmd[0], "history") == 0 || my_strcmp(cmd[0], "!") == 0)
        return (14);
    return (i);

}

void use_my_cmd(infos *inf, char **cmd, int *index)
{
    char **tab = NULL;
    int i = 0;

    cmd = remove_double_backslach(cmd);
    inf->history = create_history(cmd, inf->history);
    while ((*index <= my_tablen(cmd))
            || i < how_many_this(cmd, ";")) {
        *inf->index2 = 0;
        tab = cut_my_cmd(cmd, ";", index);
        if (!cmd_var(&tab, inf))
            return;
        or_and_or(inf, tab);
        free_my_tab(tab);
        if (*index >= my_tablen(cmd))
            break;
        i++;
    }
}

void minishell(infos *inf)
{
    char **cmd;
    char *line;

    inf->history = init_history();
    while (1) {
        *inf->index = 0;
        (isatty(0) != 0) ? my_putstr("$> ") : 0;
        if ((line = get_next_line(0)) == NULL) {
            1 ? cmd = malloc(sizeof(char *) * 1 + 8), cmd[0] = NULL : 0;
        }
        else {
            line = quote_manager(line, inf);
            if (!line)
                continue;
            line = recup_cmd(line);
            cmd = my_str_to_word_array(line);
            cmd = alias_manager(cmd, inf);
        }
        use_my_cmd(inf, cmd, inf->index);
        1 ? free_my_tab(cmd), free(line) : 0;
    }
}
