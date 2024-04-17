/*
** EPITECH PROJECT, 2024
** my_itostr.c
** File description:
** Convert an interger into a string
*/

#include <my_lib.h>

static size_t nbrlen(int nb)
{
    size_t len = 0;

    if (nb < 0) {
        len++;
        nb *= -1;
    }
    if (nb == 0)
        len++;
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return len;
}

char *my_itostr(int nb)
{
    size_t index = nbrlen(nb);
    char *snb = malloc(sizeof(char) * (index + 1));

    snb[index] = '\0';
    index--;
    if (nb < 0) {
        snb[0] = '-';
        nb *= -1;
    }
    if (nb == 0)
        snb[0] = '0';
    while (nb > 0) {
        snb[index] = nb % 10 + '0';
        nb /= 10;
        index--;
    }
    return snb;
}
