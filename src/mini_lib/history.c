/*
** EPITECH PROJECT, 2018
** history
** File description:
** Implementation of history
*/

#include "mysh.h"

history_t *add_link(history_t *begin, char **cmd)
{
    history_t *info = malloc(sizeof(history_t));
    time_t tm = {0};

    if (!info)
        return (NULL);
    info->cmd = my_tab_dup(cmd);
    time(&tm);
    info->hour = localtime(&tm);
    info->next = NULL;
    if (begin == NULL) {
        info->prev = NULL;
    } else {
        info->prev = begin;
        begin->next = info;
    }
    return (info);
}

info_history_t init_history(void)
{
    info_history_t info;

    info.first = NULL;
    info.last = NULL;
    info.total = 0;
    return (info);
}

info_history_t create_history(char **cmd, info_history_t history)
{
    history_t *hist = NULL;

    if (!cmd || !*cmd)
        return (history);
    if (history.total > 0)
        hist = history.last;
    if (hist == NULL) {
        hist = add_link(hist, cmd);
        history.first = hist;
        history.last = hist;
        history.total += 1;
    } else {
        hist = add_link(hist, cmd);
        history.last = hist;
        history.total += 1;
    }
    return (history);
}