/*
** EPITECH PROJECT, 2019
** error management
** File description:
** check errors
*/

#include "mysh.h"

void error_perm(char *cmd, int error)
{
    if (error == EACCES) {
        my_putstr(cmd);
        my_putstr(": ");
        my_perror("Permission denied.\n");
    }
}

void error_arc(char *cmd, int error)
{
    if (error == ENOEXEC) {
        my_putstr(cmd);
        my_putstr(": ");
        my_perror("Exec format error. Wrong Architecture.\n");
    }
}
