/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** my_strncmp
*/

#include <my_lib.h>

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;

    while (i < n && s1[i] && s1[i] == s2[i])
        i++;
    if (i == n)
        return 0;
    return 1;
}
