/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Implementation of 42sh
*/

#ifndef PSU_42SH_2018_42SH_H
#define PSU_42SH_2018_42SH_H

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdbool.h>
#include <features.h>
#include <time.h>

//OUR_HEADER
#include "include_folder/linked_list.h"
#include "include_folder/structure_hd.h"
#include "include_folder/separator.h"
#include "include_folder/building_hd.h"
#include "include_folder/mini_lib.h"
#include "include_folder/pipe.h"
#include "include_folder/redirection.h"
#include "include_folder/exec.h"
#include "include_folder/alias.h"

void minishell(infos *);
int found_cmd(char **, char **);
void use_my_cmd(infos *, char **, int *);
int how_many_simple(char const *str, char c);
int (*cmd_ptr[15])(char **, infos *);

#endif //PSU_42SH_2018_42SH_H
