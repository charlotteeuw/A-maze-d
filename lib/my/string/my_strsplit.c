/*
** EPITECH PROJECT, 2024
** my_strsplit
** File description:
** Splits a string into and array of strings
*/

#include <my_lib.h>

static size_t count_token(const char *str, const char *sep)
{
    size_t count = 0;
    size_t index = 0;

    while (str[index]) {
        while (str[index] && my_strchr(sep, str[index]) != NULL)
            index++;
        if (!str[index])
            break;
        count++;
        while (str[index] && my_strchr(sep, str[index]) == NULL)
            index++;
    }
    return count;
}

char **my_strsplit(const char *str, const char *sep)
{
    char **arr = malloc(sizeof(char *) * (count_token(str, sep) + 1));
    size_t beg = 0;
    size_t end = 0;
    size_t index = 0;

    while (str[end]) {
        while (str[beg] && my_strchr(sep, str[beg]) != NULL)
            beg++;
        if (!str[beg])
            break;
        end = beg;
        while (str[end] && my_strchr(sep, str[end]) == NULL)
            end++;
        arr[index] = malloc(sizeof(char) * (end - beg + 1));
        arr[index] = my_strncpy(arr[index], str + beg, end - beg);
        index++;
        beg = end;
    }
    arr[index] = NULL;
    return arr;
}
