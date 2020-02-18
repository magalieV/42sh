/*
** EPITECH PROJECT, 2018
** mini_lib
** File description:
** Implementation of mini_lib
*/

#ifndef PSU_42SH_2018_MINI_LIB_H
#define PSU_42SH_2018_MINI_LIB_H

//FREE
void free_my_tab(char **);
void free_my_env(infos *);

//GET_NEXT_LINE
char *get_next_line(int);
char *read_next_n_bytes(int);

//GET_NBR
int my_getnbr(char const *);

//PUTSTR
void my_putstr(char const *);

//STR_TO_WORD
char **my_str_to_word_array(char const *);
int len_quotes(char const *, int, char);
char *copy_cause_quotes(char *, int, char, int);
int my_word(char const *, int);
int how_many_words_suit(char const *, int);
int bool_char(char);

//STRCAT_PROPERLY
char const *my_strcat_properly(char *, char *);

//STRCMP
int my_strncmp(char const *, char const *, int);
int my_strcmp(char const *, char const *);
int my_tabcmp(char **, char **);

//STRDUP
char *my_strdup(char const *);

//COUNT_LEN
int my_tablen(char **);
int my_strlen(char *);

//GET_HOME
void get_home(infos *);

//HOW_MANY_CHAR
int how_many_char(char const *, char);

//MY_PERROR
void my_perror(char const *);

//CHANGE_MY_VALUE
int change_my_value(infos *);
element *found_my_var(char *, infos *);

//CHECK_ARG
int check_arg(char const *);

//CHECK_PERM
int check_perm(char **);

//CHECK_THAT_DIR
int check_that_dir(char const *);

//EPUR
char *epurvalue(char const *);
char *epurvar(char const *);
char **remove_first_cmd(char **);

//NO_CMD
int no_cmd(char **, infos *);
int try_cmds(char **, infos *);
int check_permission(char *);
int find_name(char *);
char *my_strcat_wof(char *, char *);

//MY_REALLOC
char *my_realloc(char *, size_t, char *);
char **my_tab_dup(char **);

//PARSING_CMD
char *recup_cmd(char *);
char **remove_double_backslach(char **);
char *replace_double_hash(char *str);
char *modify_cmd(char *str, char *string);
int count_number_slach(char *str, int i);
char *pars_my_cmd(char *str, int *n, char *string, char *tmp);

//HISTORY
info_history_t create_history(char **, info_history_t);
info_history_t init_history(void);
history_t *add_link(history_t *begin, char **cmd);

#endif //PSU_42SH_2018_MINI_LIB_H
