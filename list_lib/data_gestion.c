/*
** EPITECH PROJECT, 2019
** ACC_linked_list
** File description:
** TODO: add description
*/

#include "mysh.h"

void print_data(data_t *data)
{
    printf("name = %s\tvalue = %s\tbool = %d\n", data->name,
    data->value, data->bol);
}

data_t *init_data_bis(char *name, char *value, int i)
{
    data_t *to_return = malloc(sizeof(data_t));

    to_return->name = strdup(name);
    to_return->value = value;
    to_return->bol = i;
    return (to_return);
}

data_t *init_data(char *name, char *value)
{
    data_t *to_return = malloc(sizeof(data_t));

    to_return->name = strdup(name);
    to_return->value = value;
    return (to_return);
}

void destroy_data(data_t *data)
{
}