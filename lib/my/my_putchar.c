/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** Write a character on stdout
*/

#include <my_lib.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}
