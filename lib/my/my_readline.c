/*
** EPITECH PROJECT, 2024
** my_readline
** File description:
** my_readline
*/

#include <my_lib.h>

int my_readline(char **lineptr)
{
    char *buff = malloc(sizeof(char) * 2048);
    char c = '\0';
    int len = 0;

    while (read(0, &c, 1) == 1 && c != '\n') {
        buff[len] = c;
        len++;
    }
    buff[len] = '\0';
    *lineptr = my_strdup(buff);
    free(buff);
    if (c != '\n')
        return -1;
    return len;
}
