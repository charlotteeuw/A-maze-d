/*
** EPITECH PROJECT, 2024
** my_arrappend.c
** File description:
** my_arrappend.c
*/

#include <my_lib.h>

void *my_arrappend(void *ptr, void *elem)
{
    void ***arr = ptr;
    size_t len = my_arrlen(*arr);
    void **new = my_allocarray(len + 2);

    my_arrcpy(new, *arr);
    new[len] = elem;
    new[len + 1] = NULL;
    free(*arr);
    *arr = new;
    return *arr;
}
