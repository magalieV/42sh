/*
** EPITECH PROJECT, 2018
** separator_redirection
** File description:
** Implementation of separator_redirection
*/

#include "mysh.h"

bool execute_cdm(infos *env, char **str, bool bolean)
{
    bool bol = false;

    bol = multi_redirect(str, env);
    return (bol);
}