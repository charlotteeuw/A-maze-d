/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** Copies the content of string src into string dest
*/

#include <my_lib.h>

char *my_strcpy(char *dest, const char *src)
{
    size_t i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
