/*
** EPITECH PROJECT, 2024
** my_freearray.c
** File description:
** Free an array of pointers
*/

#include <my_lib.h>

void my_freearray(void *ptr)
{
    void **arr = ptr;

    for (size_t i = 0; arr[i]; i++) {
        free(arr[i]);
    }
    free(ptr);
}
