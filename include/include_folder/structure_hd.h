/*
** EPITECH PROJECT, 2018
** structure_hd
** File description:
** Implementation of structure_hd
*/

#ifndef PSU_42SH_2018_STRUCTURE_HD_H
#define PSU_42SH_2018_STRUCTURE_HD_H

#ifndef READ_SIZE
#define READ_SIZE (128)
#endif

typedef struct history_s {
    char **cmd;
    struct tm *hour;
    struct history_s *next;
    struct history_s *prev;
} history_t;

typedef struct info_history_s {
    history_t *first;
    history_t *last;
    int total;
} info_history_t;

typedef struct element element;
typedef struct infos infos;
typedef struct pipecmd pipecmd;

struct pipecmd
{
    char **cmd;
    pipecmd *next;
};

struct element
{
    element *next;
    element *prev;
    char *var;
    char *value;
};

struct infos
{
    element *first;
    element *last;
    info_history_t history;
    dlist_t *local_var;
    dlist_t *alias;
    int len;
    int exit;
    int *index;
    int *index2;
    int index3;
    int *indexpipe;
    char **path;
    char **env;
    char *home;
    char *pwd;
    char *oldpwd;
    pipecmd *pipelist;
};

#endif //PSU_42SH_2018_STRUCTURE_HD_H
