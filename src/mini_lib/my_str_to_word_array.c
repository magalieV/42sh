/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Creates an array of words with an str
*/

#include "mysh.h"

int bool_char(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97
        && c <= 122) || (c >= 48 && c <= 57)
        || c == '/' || c == '.' || c == '-' || c == '_' || c == '+'
        || c == '*' || c == '=' || c == '<' || c == '>' || c == '|' || c == ';'
        || c == '$' || c == '?' || c == '&' || c == '\\' || c == '!' || c == 34
        || c == 39)
        return (1);
    else
        return (0);
}

int how_many_words(char const *str)
{
    int i = 0;
    int j = 0;

    if (str[0] == '\0')
        return (1);
    while (str[j] != '\0') {
        if (bool_char(str[j]) == 1) {
            i++;
            j = how_many_words_suit(str, j);
        } else
            j++;
    }
    return (i);
}

int my_word(char const *str, int i)
{
    int j = 0, k = 0, wordlen = 0;

    for (k = 0; k <= i && str[j]; k++) {
        wordlen = 0;
        while (bool_char(str[j]) == 0)
            j++;
        while (bool_char(str[j]) == 1) {
            if (str[j] == 34) {
                wordlen = len_quotes(str, j, 34) - j - 2;
                j = len_quotes(str, j, 34);
            }
            if (str[j] == 39) {
                wordlen = len_quotes(str, j, 39) - j - 2;
                j = len_quotes(str, j, 39);
            }
            j++;
            wordlen++;
        }
    }
    return (wordlen);
}

char *purify_cmd(char const *str)
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

char **my_str_to_word_array(char const *str)
{
    int i = 0, j = 0, k = 0;
    char *cmd = purify_cmd(str);
    char **tab = malloc(sizeof(char *) * how_many_words(cmd) + 8);

    if (cmd == NULL)
        return (NULL);
    for (i = 0; i < how_many_words(cmd); i++) {
        for (; bool_char(cmd[j]) == 0 && cmd[j] != '\0'; j++);
        if (cmd[j] == 34 || cmd[j] == 39) {
            tab[i] = copy_cause_quotes(cmd, j, cmd[j], i);
            j = len_quotes(cmd, j, cmd[j]) + 1;
            continue;
        }
        tab[i] = malloc(sizeof(char) * my_word(cmd, i) + 1);
        while (bool_char(cmd[j]) == 1)
                tab[i][k++] = cmd[j++];
        tab[i][k] = '\0';
        k = 0;
    }
    tab[i] = NULL;
    return (tab);
}
