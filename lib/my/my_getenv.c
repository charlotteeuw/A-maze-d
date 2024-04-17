/*
** EPITECH PROJECT, 2024
** my_getenv
** File description:
** my_getenv
*/

#include <my_lib.h>

char *my_getenv(const char *name)
{
    char *value;
    int len = my_strlen(name);
    size_t i = 0;

    if (environ == NULL || name == NULL)
        return NULL;
    while (environ[i] != NULL && my_strncmp(name, environ[i], len))
        i++;
    if (environ[i] == NULL)
        return NULL;
    value = my_strdup(environ[i] + len + 1);
    return value;
}
