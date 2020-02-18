/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias.h
*/

#ifndef PSU_42SH_2018_ALIAS_H
#define PSU_42SH_2018_ALIAS_H

//alias.c
int char_alias(char c);
char *epur_alias_bis(char *);
char **epur_alias(char **);
char **modify_cmd_alias(char **, char **, int);
char **alias_manager(char **, infos *);
char **str_array_quote(char const *);
char **str_array_alias(const char *);
char *my_revstr(char *);

//alias_bis.c
int nb_alias(infos *);
char **get_info_bashrc(infos *);
int check_alias(char **, infos *);
int get_alias_bashrc_bis(infos *, char **);
int get_alias_bashrc(infos *);

//cmd_alias.c
int cmd_alias(char **, infos *);
int add_alias(char **, infos *);
char *test(char **, infos *);
void print_alias(dlist_t *);
int print_alias_value(infos *, char *);

//cmd_unalias.c
int cmd_unalias(char **, infos *);
int remove_alias(char **, infos *);
int remove_alias_bis(char **, infos *, int);
#endif //PSU_42SH_2018_ALIAS_H
