/*
** EPITECH PROJECT, 2024
** my_putnbr.c
** File description:
** my_putnbr.c
*/

#include <my_lib.h>

int my_putnbr(int nb)
{
    char *snb = my_itostr(nb);
    int size = 0;

    size = my_putstr(snb);
    free(snb);
    return size;
}
