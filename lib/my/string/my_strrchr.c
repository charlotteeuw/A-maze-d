/*
** EPITECH PROJECT, 2024
** my_strrchr
** File description:
** my_strcchr.c
*/

#include <my_lib.h>

const char *my_strrchr(const char *str, char c)
{
    size_t i = my_strlen(str);

    while (i != 0) {
        if (str[i - 1] == c)
            return str + i - 1;
        i--;
    }
    return NULL;
}
