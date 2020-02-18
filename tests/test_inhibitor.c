/*
** EPITECH PROJECT, 2018
** test_inhibitor
** File description:
** Implementation of test_inhibitor
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <ctype.h>

Test(inhibitor, modify_cmd_ok)
{
    char *string = my_strdup("ab");

    string = modify_cmd(NULL, string);
    cr_assert_str_eq(string, "ab\\\\");
}

Test(inhibitor, recup_cmd_ko)
{
    char *recup = NULL;

    recup = recup_cmd(NULL);
    if (recup != NULL)
        cr_assert_fail();
}

Test(inhibitor, recup_cmd_ok)
{
    char *cmd = my_strdup("bonjours\\ salut");

    cmd = recup_cmd(cmd);
    cr_assert_str_eq(cmd, "bonjours\\\\salut");
}

Test(inhibitor, recup_cmd_ko_2)
{
    char *cmd = my_strdup("bonjours\\  salut");

    cmd = recup_cmd(cmd);
    cr_assert_str_eq(cmd, "bonjours\\\\   salut");
}

Test(inhibitor, replace_double_hash_ko)
{
    char *recup = replace_double_hash(NULL);

    if (recup != NULL)
        cr_assert_fail();
}

Test(inhibitor, replace_double_hask_ok)
{
    char *cmd = my_strdup("bonjours\\\\salut");
    char *recup = replace_double_hash(cmd);

    cr_assert_str_eq(recup, "bonjours salut");
}

Test(inhibitor, remove_double_backslach_ko)
{
    char **recup = remove_double_backslach(NULL);

    if (recup != NULL)
        cr_assert_fail();
}

Test(inhibitor, remove_double_backslach_ok)
{
    char **cmd = malloc(sizeof(char) * 2);

    cmd[0] = my_strdup("bonjours\\\\salut");
    cmd[1] = 0;
    cmd = remove_double_backslach(cmd);
    cr_assert_str_eq(cmd[0], "bonjours salut");
}

Test(inhibitor, remove_double_backslach_ok_2)
{
    char **cmd = malloc(sizeof(char) * 2);

    cmd[0] = my_strdup("bonjours");
    cmd[1] = 0;
    cmd = remove_double_backslach(cmd);
    cr_assert_str_eq(cmd[0], "bonjours");
}