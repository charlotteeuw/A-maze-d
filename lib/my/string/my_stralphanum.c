/*
** EPITECH PROJECT, 2024
** my_stralphanum.c
** File description:
** Check if a string is alphanumerical
*/

#include <my_lib.h>

bool_t my_stralphanum(char *str)
{
    size_t i = 0;

    while (IS_ALPHA(str[i]) || IS_NUM(str[i])) {
        i++;
    }
    return !str[i];
}
