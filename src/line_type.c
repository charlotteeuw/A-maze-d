/*
** EPITECH PROJECT, 2024
** line_type.c
** File description:
** line_type.c
*/

#include <amazed.h>

bool_t is_comment(const char *str)
{
    bool_t is_comment = FALSE;
    char **line = my_strsplit(str, " \t");

    if (line[0][0] == '#' &&
        my_strcmp(line[0], "##start") != 0 &&
        my_strcmp(line[0], "##end") != 0)
        is_comment = TRUE;
    my_freearray(line);
    return is_comment;
}

bool_t is_command(const char *str)
{
    bool_t command = FALSE;
    char **line = my_strsplit(str, " \t");

    if (my_strcmp(line[0], "##start") == 0 || my_strcmp(line[0], "##end") == 0)
        command = TRUE;
    my_freearray(line);
    return command;
}

static bool_t check_ends(char *str)
{
    char **tunnel;
    bool_t good_ends = TRUE;

    tunnel = my_strsplit(str, "-");
    if (my_arrlen(tunnel) != 2)
        good_ends = FALSE;
    my_freearray(tunnel);
    return good_ends;
}

bool_t is_tunnel(const char *str)
{
    size_t count = 0;
    char *copy = my_strdup(str);
    char **line;
    bool_t is_tunnel = TRUE;

    rm_comments(copy);
    for (size_t i = 0; copy[i] != '\0'; i++)
        count += copy[i] == '-' ? 1 : 0;
    if (count != 1)
        is_tunnel = FALSE;
    line = my_strsplit(copy, " \t");
    if (my_arrlen(line) != 1)
        is_tunnel = FALSE;
    else if (check_ends(line[0]) != 1)
        is_tunnel = FALSE;
    my_freearray(line);
    free(copy);
    return is_tunnel;
}

bool_t is_room(const char *str)
{
    char **line;
    char *copy = my_strdup(str);
    bool_t is_room = TRUE;

    rm_comments(copy);
    line = my_strsplit(copy, " \t");
    if (is_room && my_arrlen(line) != 3)
        is_room = FALSE;
    if (is_room && !my_stralphanum(line[0]))
        is_room = FALSE;
    if (is_room && (!my_strnum(line[1]) || !my_strnum(line[2])))
        is_room = FALSE;
    my_freearray(line);
    free(copy);
    return is_room;
}

bool_t is_robot(const char *str)
{
    char **line = my_strsplit(str, " \t");
    bool_t is_robot = TRUE;

    if (my_arrlen(line) != 1)
        is_robot = FALSE;
    if (!my_strnum(line[0]))
        is_robot = FALSE;
    my_freearray(line);
    return is_robot;
}
