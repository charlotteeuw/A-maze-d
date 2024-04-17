/*
** EPITECH PROJECT, 2024
** my_arrlen.c
** File description:
** Compute the length of an array of pointers
*/

#include <my_lib.h>

size_t my_arrlen(void *ptr)
{
    void **arr = ptr;
    size_t len = 0;

    while (arr[len]) {
        len++;
    }
    return len;
}
