/*
** EPITECH PROJECT, 2019
** ACC_linked_list
** File description:
** TODO: add description
*/

#include "mysh.h"

void print_dlist(dlist_t *list)
{
    if (is_empty_dlist(list))
        return;
    for (node_t *tmp = list->begin; tmp; tmp = tmp->next)
        print_data(tmp->data);
}

bool is_empty_dlist(dlist_t *list)
{
    if (!list)
        return (true);
    else
        return (false);
}

data_t *get_data_at_index(dlist_t *list, int index)
{
    node_t *tmp = NULL;

    if (index > dlist_length(list)) {
        return (NULL);
    } else {
        tmp = list->begin;
        for (int i = 0; i < index; ++i, tmp = tmp->next);
    }
    return (tmp->data);
}

void clear_dlist(dlist_t **list)
{
    while (!is_empty_dlist(*list))
        pop_front(list);
}

int dlist_length(dlist_t *list)
{
    return (list->length);
}
