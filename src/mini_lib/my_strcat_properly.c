/*
** EPITECH PROJECT, 2019
** my_strcat_properly
** File description:
** for cd
*/

#include "mysh.h"

char const *my_strcat_properly(char *dest, char *src)
{
    char *final = NULL;
    int i = 1;
    int j = 1;

    while (dest && dest[i] && i++);
    while (src && src[j] && j++);
    if ((final = malloc(sizeof(char) * (i + j) + 1)) == NULL)
        return (NULL);
    i = 0;
    while (dest && dest[i])
        1 ? final[i] = dest[i], i++ : 0;
    j = 0;
    while (src && src[j])
        final[i++] = src[j++];
    j = 0;
    while (src && src[j])
        1 ? src[j] = '\0', j++ : 0;
    final[i] = '\0';
    (src && my_strcmp(src, "/") == 0) ? free(src) : 0;
    return (final);
}
