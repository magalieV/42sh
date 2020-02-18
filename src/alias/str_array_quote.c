/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Creates an array of words with an str
*/

#include "mysh.h"

int bool_char_quote(char c)
{
    if ((c >= 33 && c < 61) || (c > 61 && c <= 126))
        return (1);
    else
        return (0);
}

int how_many_words_quote(char const *str)
{
    int i = 0;
    int j = 0;

    if (str[0] == '\0')
        return (1);
    while (str[j] != '\0') {
        if (bool_char_quote(str[j]) == 1) {
            i++;
            while (bool_char_quote(str[j]) == 1)
                j++;
        }
        else
            j++;
    }
    return (i);
}

int my_word_quote(char const *str, int i)
{
    int j = 0;
    int k = 0;
    int wordlen = 0;

    for (k = 0; k <= i && str[j]; k++) {
        wordlen = 0;
        while (bool_char_quote(str[j]) == 0)
            j++;
        while (bool_char_quote(str[j]) == 1) {
            j++;
            wordlen++;
        }
    }
    return (wordlen);
}

char *purify_cmd_quote(char const *str)
{
    char *cmd = NULL;
    int i = 0, j = 0, k = 0, d = 0;
    int res = how_many_simple(str, '|') + how_many_char(str, ';');

    if (res == 0 && str == NULL)
        return (NULL);
    for (i = 0; str[i]; i++);
    if ((cmd = malloc(sizeof(char) * (i + (res * 2) + 1))) == NULL)
        return (NULL);
    while (str[j]) {
        if (str[j] == ';' || (str[j] == '|' && str[j + 1] != '|')) {
            (str[j - 1] != '|' ) ? cmd[k] = ' ', d = 1 : 0;
            1 ? cmd[k + d] = str[j++], cmd[k + 1 + d] = ' ', k += 2 + d : 0;
            d = 0;
        }
        else
            cmd[k++] = str[j++];
    }
    cmd[k] = '\0';
    return (cmd);
}

char **str_array_quote(char const *str)
{
    int i = 0, j = 0, k = 0;
    char *cmd = purify_cmd_quote(str);
    char **tab = malloc(sizeof(char *) * how_many_words_quote(cmd) + 8);

    for (i = 0; i < how_many_words_quote(cmd); i++) {
        tab[i] = malloc(sizeof(char) * my_word_quote(cmd, i) + 1);
        while (bool_char_quote(cmd[j]) == 0 && cmd[j] != '\0')
            j++;
        while (bool_char_quote(cmd[j]) == 1) {
            tab[i][k] = cmd[j];
            j++;
            k++;
        }
        tab[i][k] = '\0';
        k = 0;
    }
    tab[i] = NULL;
    return (tab);
}
