/*
** EPITECH PROJECT, 2019
** copy_cause_quotes
** File description:
** made by me
*/

#include "mysh.h"

char *copy_cause_quotes(char *cmd, int index, char quote, int k)
{
    char *line = malloc(sizeof(char) * my_word(cmd, k) + 1);
    int i = index + 1;
    int j = 0;

    while (cmd[i] && cmd[i] != quote) {
        line[j] = cmd[i];
        i++;
        j++;
    }
    line[j] = '\0';
    return (line);
}