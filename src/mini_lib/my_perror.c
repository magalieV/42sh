/*
** EPITECH PROJECT, 2019
** my_perror
** File description:
** prints on error output
*/

#include "mysh.h"

void my_perror(char const *s)
{
    int i = 0;

    while (s[i]) {
        write(2, &s[i], 1);
        i++;
    }
}
