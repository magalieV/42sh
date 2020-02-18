/*
** EPITECH PROJECT, 2018
** my_realloc
** File description:
** Implementation of my_realloc
*/

#include "mysh.h"

char **my_tab_dup(char **str)
{
    int len = my_tablen(str);
    char **tab = NULL;
    int i = 0;

    if (len <= 0 || ((tab = malloc(sizeof(char *) * (len + 1))) == NULL))
        return (NULL);
    for (i = 0; str[i]; i++) {
        tab[i] = my_strdup(str[i]);
    }
    tab[i] = 0;
    return (tab);
}

static char *copy_buffer_of_my_realloc(char *buffer, size_t size, char *second)
{
    char *new = malloc(size + 1);
    int i = 0;
    int j = 0;

    if (!new)
        return (NULL);
    while (buffer && buffer[i] && i < size) {
        new[i] = buffer[i];
        i++;
    }
    while (second && second[j] && i < size) {
        new[i] = second[j];
        i++;
        j++;
    }
    new[i] = '\0';
    free(buffer);
    return (new);
}

char *my_realloc(char *type, size_t size, char *second)
{
    if (size == 0) {
        if (type != NULL) {
            free(type);
            type = NULL;
        }
        return (type);
    }
    type = copy_buffer_of_my_realloc(type, size, second);
    return (type);
}