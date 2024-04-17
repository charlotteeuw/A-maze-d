/*
** EPITECH PROJECT, 2024
** my_strnum.c
** File description:
** Check if a string is numerical
*/

#include <my_lib.h>

bool_t my_strnum(char *str)
{
    size_t i = 0;

    while (IS_NUM(str[i])) {
        i++;
    }
    return !str[i];
}
