/*
** EPITECH PROJECT, 2018
** redirection
** File description:
** Implementation of redirection
*/

#ifndef PSU_42SH_2018_REDIRECTION_H
#define PSU_42SH_2018_REDIRECTION_H

typedef struct ptr_cmd_s {
    char *cmd;
    int (*sort)(char **cmd, infos *inf);
} ptr_cmd_t;

//REDIRECTIONS
int redirections(char **, infos *);
char *recup_path(char **, char *param);

//DOUBLES_REDIRECTIONS
bool redirection_double_left(infos *, char **, bool);
char *get_my_buffer(char **);
bool redirection_double_right(infos *, char **, bool);
bool multi_redirect(char **cmd, infos *env);

//REDIRECTIONS
bool execute_simple_redirection(infos *, char **, int, bool);
bool reaffect_std(int[2]);
bool create_file(int, char const *, char const **);
int found_my_cmd(char **, infos *);
int open_all_file(char const **, int);

//SEARCH_REDIRECT
bool search_param(char **, char *);
int count_redirect(char **);
bool error_redirect(void);
char **decoup_redirect(char **cmd);

//PARS
char **convert_cmd(char **cmd);
char **copy_my_arg(char **cmd, char **new_cmd, int i, int *k);
bool multi_redirect_double(char **cmd, infos *env);

#endif //PSU_42SH_2018_REDIRECTION_H
