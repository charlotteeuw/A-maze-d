/*
** EPITECH PROJECT, 2024
** error_checking.c
** File description:
** error checking
*/

#include <amazed.h>
#include <string.h>

int positions_error(char **input)
{
    int start = 0;
    int end = 0;

    for (int i = 0; input[i]; i++) {
        if (my_strcmp(input[i], "##start") == 0)
            start++;
        if (my_strcmp(input[i], "##end") == 0)
            end++;
    }
    if (start != 1 || end != 1)
        return 1;
    return 0;
}

int no_pipe(char **input)
{
    int count = 0;

    for (int i = 0; input[i]; i++) {
        if (is_tunnel(input[i]))
            count++;
    }
    if (count == 0)
        return 1;
    return 0;
}

int no_room(char **input)
{
    int count = 0;

    for (int i = 0; input[i]; i++) {
        if (is_room(input[i]))
            count++;
    }
    if (count == 0)
        return 1;
    return 0;
}

static int check_multiple_rooms(char **rooms)
{
    char **line = NULL;
    char **ref = my_strsplit(rooms[0], " \t");

    for (int i = 1; rooms[i]; i++) {
        line = my_strsplit(rooms[i], " \t");
        if (my_strcmp(line[0], ref[0]) == 0 ||
            (my_strcmp(line[1], ref[1]) == 0 &&
            my_strcmp(line[2], ref[2]) == 0))
            return 1;
    }
    return 0;
}

int rooms_error(char **input)
{
    char **rooms;
    size_t nb_rooms = 0;
    size_t j = 0;

    for (size_t i = 0; input[i]; i++) {
        if (is_room(input[i]))
            nb_rooms++;
    }
    rooms = malloc(sizeof(char *) * (nb_rooms + 1));
    for (size_t i = 0; input[i]; i++) {
        if (is_room(input[i])) {
            rooms[j] = input[i];
            j++;
        }
    }
    rooms[j] = NULL;
    for (size_t i = 0; rooms[i]; i++)
        if (check_multiple_rooms(&rooms[i]))
            return 1;
    return 0;
}

int input_error(char **input)
{
    char **line = my_strsplit(input[0], " ");

    if (my_arrlen(line) != 1 || !my_strnum(line[0]))
        return 1;
    for (int i = 0; input[i]; i++) {
        if (my_strcmp(input[i], "##start") == 0 &&
            (input[i + 1] == NULL || !(is_room(input[i + 1]))))
            return 1;
        if (my_strcmp(input[i], "##end") == 0 &&
            (input[i + 1] == NULL || !(is_room(input[i + 1]))))
            return 1;
    }
    return 0;
}
