/*
** EPITECH PROJECT, 2024
** my_stradd.c
** File description:
** Add two strings
*/

#include <my_lib.h>

char *my_stradd(char *s1, char *s2)
{
    char *s3 = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    size_t i = 0;
    size_t j = 0;

    while (s1[i]) {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j]) {
        s3[i + j] = s2[j];
        j++;
    }
    return s3;
}
