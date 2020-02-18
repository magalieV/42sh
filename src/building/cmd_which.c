/*
** EPITECH PROJECT, 2019
** cmd_which.
** File description:
** Implementation of cmd_which
*/

#include "mysh.h"

char const *own_bultin[] = {
    "cd",
    "setenv",
    "unsetenv",
    "env",
    "exit",
    "!",
    "history",
    "repeat",
    "set",
    "unset",
    "which",
    "where",
    "echo",
    NULL,
};

void put_message_bultin(bool type, char *cmd, bool *is_found)
{
    bool found = false;

    for (int i = 0; own_bultin[i]; i++) {
        if (my_strcmp(own_bultin[i], cmd) == 0) {
            found = true;
            break;
        }
    }
    if (found && !type) {
        my_putstr(cmd);
        my_putstr(": shell built-in command.\n");
    } else if (found && type) {
        my_putstr(cmd);
        my_putstr(" is a shell built-in\n");
    }
    *is_found = found;
}

int cmd_my_which(char *cmd, infos *info)
{
    int i = 0;
    char *test;
    char *slash = "/";
    bool found = false;

    put_message_bultin(false, cmd, &found);
    if (found)
        return (0);
    for (i = 0; info->path[i]; i++) {
        test = my_strcat_wof(info->path[i], slash);
        test = my_strcat_wof(test, cmd);
        if (find_name(test) == 0) {
            1 ? my_putstr(test), my_putstr("\n") : 0;
            1 ? found = true, free(test) : 0;
            break;
        }
        free(test);
    }
    (!found) ? my_perror(cmd), my_perror(": Command not found.\n") : 0;
    return (0);
}

int cmd_which(char **cmd, infos *info)
{
    cmd = remove_first_cmd(cmd);
    for (int i = 0; cmd[i]; i++)
        cmd_my_which(cmd[i], info);
}

int cmd_my_where(char *cmd, infos *info)
{
    int i = 0;
    char *test;
    char *slash = "/";
    bool found = false;

    put_message_bultin(true, cmd, &found);
    for (i = 0; info->path[i]; i++) {
        test = my_strcat_wof(info->path[i], slash);
        test = my_strcat_wof(test, cmd);
        if (find_name(test) == 0) {
            my_putstr(test);
            my_putstr("\n");
            found = true;
        }
        free(test);
    }
    return (0);
}

int cmd_where(char **cmd, infos *info)
{
    cmd = remove_first_cmd(cmd);
    for (int i = 0; cmd[i]; i++)
        cmd_my_where(cmd[i], info);
}