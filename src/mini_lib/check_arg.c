/*
** EPITECH PROJECT, 2019
** check_arg
** File description:
** check an arg of setenv
*/

#include "mysh.h"

int check_arg(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < 48 || (str[i] > 57 && str[i] < 65)
            || (str[i] > 90 && str[i] < 97) || str[i] > 122) {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
            return (-1);
        }
        i++;
    }
    return (0);
}
