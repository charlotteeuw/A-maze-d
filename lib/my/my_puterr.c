/*
** EPITECH PROJECT, 2024
** my_puterr
** File description:
** Write a string on stderr
*/

#include <my_lib.h>

int my_puterr(const char *str)
{
    size_t len = my_strlen(str);

    return write(2, str, len);
}
