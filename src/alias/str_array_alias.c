/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "mysh.h"

int is_alpha_num(char c)
{
    if (c == 61 || c == 0)
        return (0);
    else
        return (1);
}

int how_many_words_alias(const char *str)
{
    int count_word = 0;

    for (int i = 0; str[i]; i++) {
        if (is_alpha_num(str[i]) == 1 && is_alpha_num(str[i+1]) == 0) {
            count_word++;
        }
    }
    return (count_word);
}

int len_word(const char *str, int a)
{
    int len = 0;

    while (is_alpha_num(str[a]) == 1) {
        len++;
        a++;
    }
    return (len);
}

int remove_space(const char *str, int a)
{
    if (is_alpha_num(str[a]) == 0) {
        while (is_alpha_num(str[a+1]) == 0) {
            a++;
        }
        a++;
    }
    return (a);
}

char **str_array_alias(const char *str)
{
    char **tab = malloc(sizeof(char *) * (how_many_words_alias(str) + 1));
    int i = 0;
    int j = 0;
    int a = 0;
    int count = 0;

    for (; i < how_many_words_alias(str); i++) {
        a = remove_space(str, a);
        tab[i] = malloc(sizeof(char) * len_word(str, a) + 1);
        count = len_word(str, a);
        for (j = 0; j < count; a++, j++)
            tab[i][j] = str[a];
        tab[i][j] = '\0';
    }
    tab[i] = NULL;
    return (tab);
}