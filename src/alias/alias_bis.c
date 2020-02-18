/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "mysh.h"

int nb_alias(infos *inf)
{
    int count = 0;
    int fd = open(my_strcat_properly(inf->home,
                    my_strdup("/.bashrc")), O_RDONLY);
    char *buff = NULL;
    char **line = NULL;

    while ((buff = get_next_line(fd))) {
        line = str_array_quote(buff);
        if (my_strcmp(line[0], "alias") == 0)
            count ++;
        free_my_tab(line);
    }
    close(fd);
    return (count);
}

char **get_info_bashrc(infos *info)
{
    int nb_aliass = nb_alias(info);
    int fd = open(my_strcat_properly(info->home,
                    my_strdup("/.bashrc")), O_RDONLY);
    char *buff = NULL, **alias = NULL, **line = NULL;

    if (nb_aliass != 0)
        alias = malloc(sizeof(char *) * (nb_aliass + 1));
    else
        return (NULL);
    for (int i = 0; (buff = get_next_line(fd));) {
        line = str_array_quote(buff);
        if (my_strcmp(line[0], "alias") == 0) {
            alias[i] = my_strdup(buff);
            i++;
        }
    }
    close(fd);
    alias[nb_aliass] = NULL;
    return (epur_alias(alias));
}

int check_alias(char **alias, infos *inf)
{
    node_t *temp = NULL;
    int bol = 0;
    char **line = NULL;
    int index = 0;

    for (temp = inf->alias->begin; temp && temp->data->bol == 1;
        temp = temp->next, index++) {
        bol = 0;
        for (int i = 0; alias[i]; i++) {
            line = str_array_alias(alias[i]);
            if (my_strcmp(line[0], temp->data->name) == 0)
                bol = 1;
        }
        if (bol == 0) {
            pop_at_index(&inf->alias, index);
        }
    }
    return (0);
}

int get_alias_bashrc_bis(infos *inf, char **alias)
{
    char **line = NULL;
    int bol = 0;
    node_t *temp = inf->alias->begin;

    for (int i = 0; alias[i]; i++) {
        temp = inf->alias->begin;
        line = str_array_alias(alias[i]);
        bol = 0;
        for (; temp; temp = temp->next) {
            if (my_strcmp(line[0], temp->data->name) == 0) {
                temp->data->value = line[1];
                bol = 1;
            }
        }
        if (bol == 0)
            push_back(&inf->alias, init_data_bis(line[0], line[1], 1));
    }
    return (0);
}

int get_alias_bashrc(infos *inf)
{
    char **alias = get_info_bashrc(inf);
    char **line = NULL;

    if (inf->alias != NULL) {
        get_alias_bashrc_bis(inf, alias);
    } else {
        for (int i = 0; alias[i]; i++) {
            line = str_array_alias(alias[i]);
            push_back(&inf->alias, init_data_bis(line[0], line[1], 1));
        }
    }
    check_alias(alias, inf);
    return (0);
}