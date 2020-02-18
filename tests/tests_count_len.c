/*
** EPITECH PROJECT, 2018
** tests_count_len
** File description:
** Implementation of tests_count_len
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <ctype.h>

Test(count_len, my_strlen_ko)
{
    int result = my_strlen(NULL);

    cr_assert_eq(result, 0);
}

Test(count_len, my_strlen_ok)
{
    int result = my_strlen("abc");

    cr_assert_eq(result, 3);
}

Test(count_len, my_tab_len_ko)
{
    int result = my_tablen(NULL);

    cr_assert_eq(result, 0);
}

Test(count_len, my_tablen_ok)
{
    char **cmd = malloc(sizeof(char *) * 3);
    int result = 0;

    cmd[0] = my_strdup("line 1");
    cmd[1] = my_strdup("line 2");
    cmd[2] = 0;
    result = my_tablen(cmd);
    cr_assert_eq(result, 2);
}

Test(my_str_to_word_array, test_ok)
{
    char *cmd = my_strdup("salut ca va");
    char **result = NULL;

    result = my_str_to_word_array(cmd);
    cr_assert_str_eq(result[0], "salut");
}

Test(my_get_nbr, get_ko)
{
    int result = my_getnbr(NULL);

    cr_assert_eq(result, 0);
}

Test(my_get_nbr, ok_positive)
{
    int result = my_getnbr("5");

    cr_assert_eq(result, 5);
}

Test(my_get_nbr, ok_neg)
{
    int result = my_getnbr("-5");

    cr_assert_eq(result, -5);
}

Test(my_get_nbr, big_nbr)
{
    int result = my_getnbr("2147483648");

    cr_assert_eq(result, 0);
}

Test(how_many_char, how_ko)
{
    int result = how_many_char(NULL, 'a');

    cr_assert_eq(result, 0);
}

Test(how_many_char, how_ok)
{
    int result = how_many_char("abcabc", 'a');

    cr_assert_eq(result, 2);
}

Test(how_many_simple, simple_ko)
{
    int result = how_many_simple(NULL, 'b');

    cr_assert_eq(result, 0);
}

Test(how_many_simple, simple_ok)
{
    int result = how_many_simple("abcabcaab", 'a');

    cr_assert_eq(result, 3);
}

Test(my_strcat_properly, no_str)
{
    char *str = (char *)my_strcat_properly(NULL, NULL);

    if (str && *str != '\0')
        cr_assert_fail();
}

Test(my_strcat_properly, one_str)
{
    char *str = (char *)my_strcat_properly("salut", NULL);

    cr_assert_str_eq(str, "salut");
}

Test(my_strcat_properly, two_str)
{
    char *str = (char *)my_strcat_properly(my_strdup("salut"),
    my_strdup("coucou"));

    cr_assert_str_eq(str, "salutcoucou");
}

Test(check_that_dir, no_filepath)
{
    int result = check_that_dir(NULL);

    cr_assert_eq(result, -1);
}

Test(check_that_dir, bad_file_path)
{
    int result = check_that_dir("bad_test");

    cr_assert_eq(result, 1);
}

Test(check_that_dir, good_file_path)
{
    int result = check_that_dir("src");

    cr_assert_eq(result, 0);
}

Test(check_that_dir, path_is_a_file)
{
    int result = check_that_dir("Makefile");

    cr_assert_eq(result, -1);
}