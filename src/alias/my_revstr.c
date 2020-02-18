/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** my_revstr.c
*/

int my_putstr_revstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = my_putstr_revstr(str)-1;
    int a = 0;
    char t;

    while (str[a] != '\0' &&  a <= i) {
        t = str[a];
        str[a] = str[i];
        str[i] = t;
        i--;
        a++;
    }
    return (str);
}
