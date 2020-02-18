/*
** EPITECH PROJECT, 2018
** building_hd
** File description:
** Implementation of building_hd
*/

#ifndef PSU_42SH_2018_BUILDING_HD_H
#define PSU_42SH_2018_BUILDING_HD_H

//CD
int cmd_cd(char **, infos *);

//ENV
int cmd_env(char **, infos *);
int check_path(infos *infos);

//EXIT
int cmd_exit(char **, infos *);
int check_exit(char *);

//SETENV
int cmd_setenv(char **, infos *);
void my_setenv(char **, infos *);
void init_e_for_setenv(char **, infos *);
element *check_tab(char **, infos *);
void check_my_list(char **, infos *);
int modify_path(infos *, char **);

//UNSETENV
int delete_var(infos *, element *);
int my_unsetenv(char **, infos *);
int cmd_unsetenv(char **, infos *);

//HISTORY
int cmd_history(char **, infos *);

//REPEAT
int cmd_repeat(char **, infos *);

//VAR
int cmd_set(char **, infos *);
int cmd_unset(char **, infos *);
char *get_local(infos *, char *);
bool cmd_var(char ***, infos *);
void print_spaces(int);

//BUILDING_OWN_ENV
infos *building_own_env(infos *);
void env_in_list(infos *, char *);
void found_path(infos *inf);

//WHICH AND WHERE
int cmd_which(char **, infos *);
int cmd_where(char **, infos *);

//ECHO
int cmd_echo(char **, infos *);
bool *found_if_good_option(char ***, int, bool *, bool *);
char **remove_n_line_on_tab(char **, int);

#endif //PSU_42SH_2018_BUILDING_HD_H
