/*
** EPITECH PROJECT, 2019
** ACC_linked_list
** File description:
** TODO: add description
*/

#include "mysh.h"

void push_no_special_case(dlist_t **list, data_t *to_add, int index)
{
    node_t *new = malloc(sizeof(data_t));
    node_t *prev = (*list)->begin;
    node_t *next = NULL;

    new->data = to_add;
    new->next = NULL;
    new->prev = NULL;
    for (int i = 0; i < index; ++i, prev = prev->next);
    next = prev->next;
    prev->next = new;
    next->prev = new;
    new->next = next;
    new->prev = prev;
}

void push_at_index(dlist_t **list, data_t *to_add, int index)
{
    if (index >= dlist_length(*list))
        return;
    if (index == 0) {
        push_front(list, to_add);
        return;
    }
    if (index == dlist_length(*list) - 1) {
        push_back(list, to_add);
        return;
    }
    push_no_special_case(list, to_add, index);
    (*list)->length++;
}

void push_back(dlist_t **list, data_t *to_add)
{
    node_t *tmp = malloc(sizeof(node_t));

    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->data = to_add;
    if (is_empty_dlist(*list)) {
        (*list) = malloc(sizeof(dlist_t));
        (*list)->length = 0;
        (*list)->begin = tmp;
        (*list)->end = tmp;
    } else {
        tmp->prev = (*list)->end;
        (*list)->end->next = tmp;
        (*list)->end = tmp;
    }
    (*list)->length++;
}

void push_front(dlist_t **list, data_t *to_add)
{
    node_t *tmp = malloc(sizeof(node_t));

    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->data = to_add;
    if (is_empty_dlist(*list)) {
        (*list) = malloc(sizeof(dlist_t));
        (*list)->length = 0;
        (*list)->begin = tmp;
        (*list)->end = tmp;
    } else {
        tmp->next = (*list)->begin;
        (*list)->begin->prev = tmp;
        (*list)->begin = tmp;
    }
    (*list)->length++;
}
