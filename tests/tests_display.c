/*
** EPITECH PROJECT, 2018
** tests_display
** File description:
** Implementation of tests_display
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <ctype.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(redirect, tests_perror_ok, .init = redirect_all_std)
{
    my_perror("test1");
    cr_assert_stderr_eq_str("test1");
}

Test(redirect, test_putstr, .init = redirect_all_std)
{
    my_putstr("test2");
    cr_assert_stdout_eq_str("test2");
}