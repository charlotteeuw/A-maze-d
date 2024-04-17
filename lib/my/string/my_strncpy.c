/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** Copie no more than n character of string src into string dest
*/

#include <my_lib.h>

char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;

    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
