/*
** EPITECH PROJECT, 2024
** my_stralpha.c
** File description:
** Check if a string is alphabetical
*/

#include <my_lib.h>

bool_t my_stralpha(char *str)
{
    size_t i = 0;

    while (IS_ALPHA(str[i])) {
        i++;
    }
    return !str[i];
}
