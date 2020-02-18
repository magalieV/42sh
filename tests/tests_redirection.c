/*
** EPITECH PROJECT, 2018
** tests_redirection
** File description:
** Implementation of tests_redirection
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <ctype.h>

Test(redirection, testing_no_redirection)
{
    infos *env = NULL;
    char **cmd = malloc(sizeof(char *) * 3);
    int result = 0;

    cmd[0] = my_strdup("cat");
    cmd[1] = my_strdup("Makefile");
    result = redirections(cmd, env);
    cr_assert_eq(result, 0);
}

Test(redirection, testing_bad_recup_path)
{
    char **cmd = NULL;
    char *recup = NULL;

    recup = recup_path(cmd, ">");
    if (recup != NULL)
        cr_assert_fail();
}

Test(redirection, testing_good_recup_path)
{
    char **cmd = malloc(sizeof(char) * 4);
    char *recup = 0;

    cmd[0] = my_strdup("ls");
    cmd[1] = my_strdup("<<");
    cmd[2] = my_strdup("my_file");
    cmd[3] = 0;
    recup = recup_path(cmd, "<<");
    cr_assert_str_eq(recup, "my_file");
}

Test(redirection, remove_file_path_ok)
{
    char **cmd = malloc(sizeof(char) * 4);
    char **recup = NULL;

    cmd[0] = my_strdup("ls");
    cmd[1] = my_strdup("<<");
    cmd[2] = my_strdup("my_file");
    cmd[3] = 0;
    recup = remove_end_cmd(cmd);
    if (recup[1] != NULL)
        cr_assert_fail();
    cr_assert_str_eq(recup[0], "ls");
}

Test(redirection, remove_path_file_ko)
{
    char **cmd = NULL;
    char **recup = NULL;

    recup = remove_end_cmd(cmd);
    if (recup != NULL)
        cr_assert_fail();
}

Test(redirection, found_my_cmd_ok)
{
    infos info = {0};
    char **cmd = malloc(sizeof(char) * 2);
    int recup = 0;

    cmd[0] = my_strdup("env");
    cmd[1] = 0;
    recup = found_my_cmd(cmd, &info);
    cr_assert_eq(recup, 0);
}

Test(redirection, found_my_cmd_ko_2)
{
    infos info = {0};
    char **cmd = NULL;
    int recup = 0;

    recup = found_my_cmd(cmd, &info);
    cr_assert_eq(recup, -1);
}

Test(redirection, open_all_flag)
{
    char **cmd = malloc(sizeof(char) * 5);
    int result = 0;

    cmd[0] = my_strdup("ls");
    cmd[1] = my_strdup(">");
    cmd[2] = my_strdup("my_file1");
    cmd[3] = my_strdup(">");
    cmd[4] = my_strdup("my_file2");
    cmd[5] = 0;
    result = open_all_file((char const **)cmd, O_RDONLY | O_CREAT);
    if (result <= 0)
        cr_assert_fail();
}

Test(redirection, create_file_neg_ko)
{
    int result = 0;

    result = create_file(0, "no_exist", NULL);
    cr_assert_eq(result, 1);
}

Test(redirection, create_file_neg_ok)
{
    int result = 0;

    result = create_file(0, "Makefile", NULL);
    cr_assert_eq(result, 0);
}

Test(redirection, create_file_pos_ok)
{
    char **cmd = malloc(sizeof(char) * 5);
    int result = 0;

    cmd[0] = my_strdup("ls");
    cmd[1] = my_strdup(">");
    cmd[2] = my_strdup("my_file1");
    cmd[3] = my_strdup(">");
    cmd[4] = my_strdup("my_file2");
    cmd[5] = 0;
    result = create_file(1, NULL, (char const **)cmd);
    cr_assert_eq(result, 0);
}

Test(redirection, reaffect_std_ko)
{
    int result = reaffect_std(NULL);

    cr_assert_eq(result, 0);
}

Test(redirection, reaffect_std_ok)
{
    int result = 0;
    int tab[2] = {0, 1};

    result = reaffect_std(tab);
    cr_assert_eq(result, 1);
}

Test(redirection, execute_simple_redirect_ko_1)
{
    int result = 0;
    infos info = {0};

    result = execute_simple_redirection(&info, NULL, 0, true);
    cr_assert_eq(result, 0);
}

Test(redirection, execute_simple_redirect_ko_2)
{
    int result = 0;
    infos info = {0};
    char **cmd = malloc(sizeof(char) * 4);

    cmd[0] = my_strdup("ls");
    cmd[1] = my_strdup("<");
    cmd[2] = my_strdup("no_exist");
    cmd[3] = 0;
    result = execute_simple_redirection(&info, cmd, 0, true);
    cr_assert_eq(result, 1);
}

Test(redirection, execute_simple_redirect_ok)
{
    int result = 0;
    infos info = {0};
    char **cmd = malloc(sizeof(char) * 5);

    cmd[0] = my_strdup("env");
    cmd[1] = my_strdup(">");
    cmd[2] = my_strdup("test10");
    cmd[3] = 0;
    result = execute_simple_redirection(&info, cmd, 1, true);
    cr_assert_eq(result, 1);
}

Test(redirection, double_redirection_right)
{
    infos info = {0};
    char **cmd = malloc(sizeof(char) * 5);
    int result = 0;

    cmd[0] = my_strdup("env");
    cmd[1] = my_strdup(">>");
    cmd[2] = my_strdup("test2");
    cmd[3] = 0;
    result = redirection_double_right(&info, cmd, true);
    cr_assert_eq(result, 1);
}

Test(redirection, get_my_buffer_ko)
{
    char *result = get_my_buffer(NULL);

    if (result != NULL)
        cr_assert_fail();
}

Test(redirection, double_redirection_left_ko)
{
    infos info = {0};
    int result = 0;

    result = redirection_double_left(&info, NULL, true);
    cr_assert_eq(result, 0);
}

Test(redirection, put_error_ambigious)
{
    int result = error_redirect();

    cr_assert_eq(result, 1);
}

Test(count_rediect, all_count)
{
    char **cmd = malloc(sizeof(char *) * 5);
    int result = 0;

    cmd[0] = my_strdup(">>");
    cmd[1] = my_strdup(">");
    cmd[2] = my_strdup("<<");
    cmd[3] = my_strdup("<");
    cmd[4] = 0;
    result = count_redirect(cmd);
    cr_assert_eq(result, 4);
}

Test(search_param, ok_search)
{
    char **cmd = malloc(sizeof(char *) * 4);
    int result = 0;

    cmd[0] = my_strdup("ls");
    cmd[1] = my_strdup(">");
    cmd[2] = my_strdup("dodo");
    cmd[3] = 0;
    result = search_param(cmd, ">");
    cr_assert_eq(result, 1);
}

Test(search_param, ko_search)
{
    char **cmd = malloc(sizeof(char *) * 4);
    int result = 0;

    cmd[0] = my_strdup("ls");
    cmd[1] = my_strdup(">");
    cmd[2] = my_strdup("dodo");
    cmd[3] = 0;
    result = search_param(cmd, "<");
    cr_assert_eq(result, 0);
}

Test(double_redirect, ko_to_much)
{
    char **cmd = malloc(sizeof(char *) * 5);
    int result = 0;
    infos info = {0};

    cmd[0] = my_strdup(">>");
    cmd[1] = my_strdup(">");
    cmd[2] = my_strdup("<<");
    cmd[3] = my_strdup("<");
    cmd[4] = 0;
    result = multi_redirect(cmd, &info);
    cr_assert_eq(result, 1);
}
