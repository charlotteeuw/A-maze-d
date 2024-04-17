/*
** EPITECH PROJECT, 2024
** my_realloc
** File description:
** my_realloc
*/

#include <my_lib.h>

void *my_realloc(void *ptr, size_t size)
{
    char *old = ptr;
    char *new = malloc(size);
    size_t i = 0;

    if (ptr == NULL)
        return malloc(size);
    while (i < (size - 1) && old[i]) {
        new[i] = old[i];
        i++;
    }
    new[i] = 0;
    free(old);
    return new;
}
