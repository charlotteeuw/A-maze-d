/*
** EPITECH PROJECT, 2024
** my_arrcpy.c
** File description:
** my_arrcpy.c
*/

#include <my_lib.h>

void *my_arrcpy(void *dest, void *src)
{
    size_t i = 0;
    void **arr_dest = dest;
    void **arr_src = src;

    while (arr_src[i]) {
        arr_dest[i] = arr_src[i];
        i++;
    }
    arr_dest[i] = NULL;
    return dest;
}
