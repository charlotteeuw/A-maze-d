/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** Returns a newly allocated string with the content of str
*/

#include <my_lib.h>

char *my_strdup(const char *str)
{
    size_t len = my_strlen(str);
    char *new = malloc(sizeof(char) * (len + 1));

    my_strcpy(new, str);
    return new;
}
