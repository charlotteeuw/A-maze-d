/*
** EPITECH PROJECT, 2024
** my_strtoi
** File description:
** Converts a numerical string into an int
*/

#include <my_lib.h>

int my_strtoi(const char *str)
{
    int nb = 0;
    int sign = 1;
    size_t i = 0;

    if (str[0] == '-' || str[0] == '+') {
        if (str[0] == '-')
            sign = -1;
        i++;
    }
    while (str[i]) {
        nb *= 10;
        nb += str[i] - '0';
        i++;
    }
    return sign * nb;
}
