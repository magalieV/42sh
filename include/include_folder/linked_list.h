/*
** EPITECH PROJECT, 2019
** ACC_linked_list
** File description:
** TODO: add description
*/

#ifndef ACC_LINKED_LIST_LINKED_LIST_H
#define ACC_LINKED_LIST_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct data_s {
    char *value;
    char *name;
    int bol;
}data_t;

typedef struct node_s {
    data_t *data;
    struct node_s *next;
    struct node_s *prev;
}node_t;

typedef struct dlist_s {
    node_t *begin;
    node_t *end;
    int length;
}dlist_t;

//ex00
data_t *init_data(char *, char *);
data_t *init_data_bis(char *name, char *value, int i);
void destroy_data(data_t *);
void print_data(data_t *);

//ex01
bool is_empty_dlist(dlist_t *);
int dlist_length(dlist_t *);
void push_front(dlist_t **, data_t *);
void print_dlist(dlist_t *);

//ex02
void push_back(dlist_t **, data_t *);
void pop_front(dlist_t **);
void pop_back(dlist_t **);
void clear_dlist(dlist_t **);

//ex03
data_t *get_data_at_index(dlist_t *, int);
void push_at_index(dlist_t **, data_t *, int);
void pop_at_index(dlist_t **, int);

#endif //ACC_LINKED_LIST_LINKED_LIST_H
