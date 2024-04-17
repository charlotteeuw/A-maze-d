/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** Returns the lenght of a string
*/

#include <my_lib.h>
#include <string.h>

size_t my_strlen(const char *str)
{
    size_t len = 0;

    while (str[len])
        len++;
    return len;
}
