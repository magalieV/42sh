/*
** EPITECH PROJECT, 2018
** exec
** File description:
** Implementation of exec
*/

#ifndef PSU_42SH_2018_EXEC_H
#define PSU_42SH_2018_EXEC_H

//MY_EXEC
int my_exec(char **, char *, infos *);
void print_error(int);
char **make_my_args(char **);

//ERROR_MANAGEMENT
void error_arc(char *, int);
void error_perm(char *, int);

#endif //PSU_42SH_2018_EXEC_H
