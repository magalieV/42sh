/*
** EPITECH PROJECT, 2018
** pipe
** File description:
** Implementation of pipe
*/

#ifndef PSU_42SH_2018_PIPE_H
#define PSU_42SH_2018_PIPE_H

//PIPE
void pipes(char **, infos *);

//PREPARED_PIPE
int add_pipecmd(infos *, char **, int);
char *which_cmd(char **, infos *);
pipecmd *prepare_my_cmd(char **, infos *);
int check_for_pipes(char **);
void exec_pipe(pipecmd *, int, infos *, pipecmd *);
void free_pipecmd(pipecmd *);
int broken_pipe(pipecmd *, pipecmd *);
int move_on(int, int);
int check_for_pipecd(infos *);

#endif //PSU_42SH_2018_PIPE_H
