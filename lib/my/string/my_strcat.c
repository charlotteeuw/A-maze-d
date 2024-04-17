/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** my_strcat
*/

#include <my_lib.h>

char *my_strcat(char *dest, const char *src)
{
    size_t len = my_strlen(dest);
    size_t i = 0;

    while (src[i]) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return dest;
}
