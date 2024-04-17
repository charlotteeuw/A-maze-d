/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** Write a string on stdout
*/

#include <my_lib.h>

int my_putstr(const char *str)
{
    size_t len = my_strlen(str);

    return write(1, str, len);
}
