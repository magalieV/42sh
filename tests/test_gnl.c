/*
** EPITECH PROJECT, 2018
** Boostrap_get_next_line
** File description:
** __DESCRIPTION__
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <ctype.h>

char *read_next_n_bytes(int fd);

void close_file(void)
{
    int fd = -1;

    if (fd == -1)
        close(fd);
}

Test(redirect, test_outputs, .fini = close_file)
{
    char *got;
    int fd = -1;

    fd = open("tests/test", O_RDONLY);
    got = get_next_line(fd);
    cr_assert_str_eq(got, "Hello my name is Chucky");
}

Test(redirect, test_outputs2, .fini = close_file)
{
    char *got;
    int fd = -1;

    fd = open("tests/false", O_RDONLY);
    got = get_next_line(fd);
    cr_assert_eq(got, NULL);
}

Test(redirect, test_outputs3, .fini = close_file)
{
    char *got;
    int fd = -1;

    fd = open("tests/test", O_RDONLY);
    got = get_next_line(fd);
    got = get_next_line(fd);
    cr_assert_str_eq(got, "Do you want to be my friend?");
}

Test(redirect, test_outputs4, .fini = close_file)
{
    char *got;
    int fd = -1;

    fd = open("tests/test2", O_RDONLY);
    got = get_next_line(fd);
    cr_assert_eq(got, NULL);
}

Test(redirect, test_outputs5, .fini = close_file)
{
    char *got;
    int fd = -1;

    fd = open("tests/false", O_RDONLY);
    got = read_next_n_bytes(fd);
    cr_assert_eq(got, NULL);
}

Test(gnl, bad_file_descriptor)
{
    char *got = get_next_line(-1);

    if (got != NULL)
        cr_assert_fail();
}