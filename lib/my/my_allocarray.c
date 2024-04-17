/*
** EPITECH PROJECT, 2024
** my_allocarray.c
** File description:
** my_allocarray.c
*/

#include <my_lib.h>

void *my_allocarray(size_t size)
{
    void **arr = malloc(sizeof(void *) * (size + 1));

    arr[0] = NULL;
    return arr;
}
