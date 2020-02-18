/*
** EPITECH PROJECT, 2018
** cmd_history
** File description:
** Implementation of cmd_history
*/

#include "mysh.h"

void my_putnbr(int nbr)
{
    int new_nbr;

    if (nbr < 0) {
        write(1, "-", 1);
        nbr *= -1;
    }
    new_nbr = nbr % 10;
    nbr /= 10;
    if (nbr > 0)
        my_putnbr(nbr);
    new_nbr += 48;
    write(1, &new_nbr, 1);
}

int cmd_history(char **cmd, infos *info)
{
    history_t *history = info->history.first;
    int count = 1;
    int i = 0;

    while (history) {
        1 ? my_putstr("\t"), my_putnbr(count) : 0;
        my_putstr("\t");
        my_putnbr(history->hour->tm_hour);
        my_putstr(":");
        my_putnbr(history->hour->tm_min);
        1 ? my_putstr("\t"), i = 0 : 0;
        count++;
        while (history->cmd[i])
            1 ? my_putstr(history->cmd[i]), i++ : 0;
        my_putstr("\n");
        if (!history->next)
            break;
        history = history->next;
    }
    return (0);
}
