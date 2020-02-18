/*
** EPITECH PROJECT, 2019
** check_that_dir
** File description:
** check a directory
*/

#include "mysh.h"

int check_that_dir(char const *filepath)
{
    DIR *dir;

    if (!filepath)
        return (-1);
    dir = opendir(filepath);
    if (dir != NULL) {
        closedir(dir);
        return (0);
    }
    if (errno == ENOTDIR) {
        return (-1);
    }
    return (1);
}
