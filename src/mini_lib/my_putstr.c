/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** print a stirng
*/

#include "mysh.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str && str[i]) {
        write(1, &str[i], 1);
        i++;
    }
}
