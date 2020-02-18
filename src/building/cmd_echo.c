/*
** EPITECH PROJECT, 2019
** cmd_echo.
** File description:
** Implementation of cmd_echo
*/

#include "mysh.h"

bool *found_option(char ***cmd)
{
    bool *options = malloc(sizeof(bool) * 3);
    bool start_echo = true;
    bool found_option = false;

    for (int i = 0; i < 2; i++)
        options[i] = false;
    if (!(*cmd) || !(*cmd)[0] || !(*cmd)[1])
        return (options);
    for (int i = 1; (*cmd)[i]; i++) {
        found_option = false;
        if (start_echo && (*cmd)[i][0] && (*cmd)[i][0] == '-')
            options = found_if_good_option(cmd, i, &found_option, options);
        if (found_option)
            i--;
        start_echo = found_option;
    }
    return (options);
}

int suit_put_special(char c, char after, int value)
{
    switch (after) {
        case 'f':
            1 ? value = 2, write(1, "\f", 1) : 0;
            break;
        case 'n':
            1 ? value = 2, write(1, "\n", 1) : 0;
            break;
        case 'r':
            1 ? value = 2, write(1, "\r", 1) : 0;
            break;
        case 't':
            1 ? value = 2, write(1, "\t", 1) : 0;
            break;
        default:
            value = 1;
            break;
    }
    return (value);
}

int put_special_case(char c, char after, bool option, int value)
{
    if (!option || c != '\\')
        return (0);
    switch (after) {
        case 'a':
            1 ? value = 2, write(1, "\a", 1) : 0;
            break;
        case 'b':
            1 ? value = 2, write(1, "\b", 1) : 0;
            break;
        case 'v':
            1 ? value = 2, write(1, "\v", 1) : 0;
            break;
        case 'e':
            1 ? value = 2, write(1, "\e", 1) : 0;
            break;
        default:
            value = suit_put_special(c, after, value);
            break;
    }
    return (value);
}

int my_put_echo(char *str, bool option)
{
    int result = 0;

    for (int i = 0; str[i]; i++) {
        result = 0;
        if (str[i + 1])
            result = put_special_case(str[i], str[i + 1], option, result);
        if (result == 0 && str[i] == '\\' && str[i + 1]) {
            write(1, &str[i + 1], 1);
            i++;
        } else if (result == 0 || result == 1)
            write(1, &str[i], 1);
        if (result == 2)
            i++;
    }
}

int cmd_echo(char **cmd, infos *info)
{
    int i = 1;
    bool *option = found_option(&cmd);

    if (how_many_this(cmd, "|\0") != 0) {
        pipes(cmd, info);
        if (info->pipelist)
            free_pipecmd(info->pipelist);
        info->pipelist = NULL;
        return (info->exit);
    }
    while (cmd && cmd[i]) {
        my_put_echo(cmd[i], option[1]);
        if (cmd[i + 1])
            my_putstr(" ");
        i++;
    }
    if (!option[0])
        my_putstr("\n");
    return (0);
}