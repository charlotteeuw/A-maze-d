/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** Compare two strings
*/

#include <my_lib.h>

int my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;

    while (s1[i] && s1[i] == s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}
