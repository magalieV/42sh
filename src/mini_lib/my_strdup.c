/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include "mysh.h"

char *my_strdup(char const *src)
{
    int len = 0;
    int i = 0;
    char *str;

    while (src && src[len])
        len++;
    if (len == 0 || (str = malloc(sizeof(char) * len + 1)) == NULL)
        return (NULL);
    while (src[i]) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
