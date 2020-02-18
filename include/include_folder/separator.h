/*
** EPITECH PROJECT, 2018
** separator
** File description:
** Implementation of separator
*/

#ifndef PSU_42SH_2018_SEPARATOR_H
#define PSU_42SH_2018_SEPARATOR_H

char **cut_my_cmd(char **, char *, int *);
int how_many_this(char **, char *);
void or_and_or(infos *, char **);

//SEPARATOR REDIRECTION
bool execute_cdm(infos *env, char **str, bool bolean);
char **remove_end_cmd(char **str);

//QUOTE
char *quote_manager(char *cmd, infos *info);
char *backticks(char const *cmd, infos *inf, int i);
char **alias_manager(char **cmd, infos *info);

#endif //PSU_42SH_2018_SEPARATOR_H
