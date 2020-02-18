/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** return a nb in a str
*/

#include "mysh.h"

static void int_size(int *result, char const *str, int j)
{
    long tempo = *result;

    if (tempo > 2147483647 || j > 10 || tempo < -2147483647) {
        *result = 0;
        return;
    }
}

int my_getnbr(char const *str)
{
    int result = 0;
    int i = 0;
    int j = 0;
    int sign = 1;

    if (!str)
        return (0);
    while (str[i] == '+' || str[i] == '-' || str[i] == '0') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = (result * 10) + str[i] - 48;
        j++;
        int_size(&result, str, j);
        i++;
    }
    result = result * sign;
    return (result);
}
