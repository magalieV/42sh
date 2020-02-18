/*
** EPITECH PROJECT, 2019
** ACC_linked_list
** File description:
** TODO: add description
*/

#include "mysh.h"

void pop_no_special_case(dlist_t **list, int index)
{
    node_t *tmp = (*list)->begin;
    node_t *next = NULL;
    node_t *prev = NULL;

    for (int i = 0; i < index; ++i, tmp = tmp->next);
    next = tmp->next;
    prev = tmp->prev;
    prev->next = next;
    next->prev = prev;
    destroy_data(tmp->data);
}

void pop_at_index(dlist_t **list, int index)
{
    if (index >= dlist_length(*list))
        return;
    if (index == 0) {
        pop_front(list);
        return;
    }
    if (index == dlist_length(*list) - 1) {
        pop_back(list);
        return;
    }
    pop_no_special_case(list, index);
    (*list)->length--;
}

void pop_back(dlist_t **list)
{
    node_t *tmp = NULL;

    if (is_empty_dlist(*list))
        return;
    if (dlist_length(*list) == 1) {
        destroy_data((*list)->begin->data);
        free((*list)->begin);
        free((*list));
        (*list) = NULL;
        return;
    } else {
        destroy_data((*list)->end->data);
        tmp = (*list)->end;
        (*list)->end = (*list)->end->prev;
        (*list)->end->next = NULL;
    }
    (*list)->length--;
}

void pop_front(dlist_t **list)
{
    node_t *tmp = NULL;

    if (dlist_length(*list) == 1) {
        destroy_data((*list)->begin->data);
        free((*list)->begin);
        free((*list));
        (*list) = NULL;
        return;
    } else {
        tmp = (*list)->begin;
        destroy_data((*list)->begin->data);
        (*list)->begin = (*list)->begin->next;
        (*list)->begin->prev = NULL;
    }
    (*list)->length--;
}