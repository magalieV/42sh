/*
** EPITECH PROJECT, 2018
** tests_my_realloc
** File description:
** Implementation of tests_my_realloc
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <ctype.h>

Test(my_realloc, test_ko_1)
{
    char *result = my_realloc(NULL, 0, NULL);

    if (result != NULL)
        cr_assert_fail();
}

Test(my_realloc, test_ko_2)
{
    char *result = my_realloc(my_strdup("abc"), sizeof(char) * 4, NULL);

    cr_assert_str_eq(result, "abc");
}

Test(my_realloc, test_ko_3)
{
    char *result = my_realloc(my_strdup("test"), 0, NULL);

    if (result != NULL)
        cr_assert_fail();
}

Test(my_realloc, test_ko_4)
{
    char *result = my_realloc(my_strdup("test"), -6, NULL);

    if (result != NULL)
        cr_assert_fail();
}

Test(my_strdup, test_ko)
{
    char *result = my_strdup(NULL);

    if (result != NULL)
        cr_assert_fail();
}

Test(my_strcmp, test_eq)
{
    int result = my_strcmp("test1", "test1");

    cr_assert_eq(result, 0);
}

Test(my_strcmp, test_not_eq)
{
    int result = my_strcmp("test1", "test2");

    cr_assert_eq(result, -1);
}

Test(my_strncmp, test_eq)
{
    int result = my_strncmp("test1", "test1", 5);

    cr_assert_eq(result, 0);
}

Test(my_strncmp, test_not_eq)
{
    int result = my_strncmp("test1", "test2", 5);

    cr_assert_eq(result, -1);
}

Test(my_tabcmp, test_no_eq)
{
    char **cmd_one = malloc(sizeof(char *) * 2);
    char **cmd_two = malloc(sizeof(char *) * 2);
    int result = 0;

    cmd_one[0] = my_strdup("test1");
    cmd_one[1] = 0;
    cmd_two[0] = my_strdup("test2");
    cmd_two[1] = 0;
    result = my_tabcmp(cmd_one, cmd_two);
    cr_assert_eq(result, 1);
}

Test(my_tabcmp, test_no_eq_1)
{
    char **cmd_one = NULL;
    char **cmd_two = malloc(sizeof(char *) * 2);
    int result = 0;

    cmd_two[0] = my_strdup("test2");
    cmd_two[1] = 0;
    result = my_tabcmp(cmd_one, cmd_two);
    cr_assert_eq(result, 1);
}

Test(my_tabcmp, test_eq)
{
    char **cmd_one = malloc(sizeof(char *) * 2);
    char **cmd_two = malloc(sizeof(char *) * 2);
    int result = 0;

    cmd_one[0] = my_strdup("test1");
    cmd_one[1] = 0;
    cmd_two[0] = my_strdup("test1");
    cmd_two[1] = 0;
    result = my_tabcmp(cmd_one, cmd_two);
    cr_assert_eq(result, 0);
}

Test(my_tab_dup, ko_1)
{
    char **result = NULL;

    result = my_tab_dup(NULL);
    if (result != NULL)
        cr_assert_fail();
}

Test(my_tab_dup, ok_1)
{
    char **result = NULL;
    char **cmd_one = malloc(sizeof(char *) * 2);

    cmd_one[0] = my_strdup("test1");
    cmd_one[1] = 0;
    result = my_tab_dup(cmd_one);
    cr_assert_str_eq(result[0], cmd_one[0]);
}

Test(ini_history, ok_init)
{
    info_history_t info;

    info = init_history();
    if (info.first != NULL || info.last != NULL || info.total != 0)
        cr_assert_fail();
}

Test(history, add_link)
{
    history_t *history = NULL;
    char **cmd_one = malloc(sizeof(char *) * 2);

    cmd_one[0] = my_strdup("test1");
    cmd_one[1] = 0;
    history = add_link(history, cmd_one);
    cr_assert_str_eq(cmd_one[0], history->cmd[0]);
}

Test(history, create_history)
{
    info_history_t info;

    info = init_history();
    info = create_history(NULL, info);
    if (info.total != 0)
        cr_assert_fail();
}

Test(history, create_history_ok_1)
{
    info_history_t info;
    char **cmd_one = malloc(sizeof(char *) * 2);

    cmd_one[0] = my_strdup("test1");
    cmd_one[1] = 0;
    info = init_history();
    info = create_history(cmd_one, info);
    cr_assert_eq(info.total, 1);
}

Test(history, create_history_ok_2)
{
    info_history_t info;
    char **cmd_one = malloc(sizeof(char *) * 2);

    cmd_one[0] = my_strdup("test1");
    cmd_one[1] = 0;
    info = init_history();
    info = create_history(cmd_one, info);
    free(cmd_one);
    cmd_one[0] = my_strdup("test33");
    info = create_history(cmd_one, info);
    cr_assert_eq(info.total, 2);
}

Test(history, create_history_ok_3)
{
    info_history_t info;
    char **cmd_one = malloc(sizeof(char *) * 2);

    cmd_one[0] = my_strdup("test1");
    cmd_one[1] = 0;
    info = init_history();
    info = create_history(cmd_one, info);
    info = create_history(cmd_one, info);
    cr_assert_eq(info.total, 2);
}