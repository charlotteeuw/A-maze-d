/*
** EPITECH PROJECT, 2024
** input.c
** File description:
** input.c
*/

#include <amazed.h>

static bool_t is_conforming(char *str, enum input_stage *stage)
{
    static bool_t command = FALSE;

    if (is_comment(str))
        return 1;
    rm_comments(str);
    if (command && !is_room(str))
        return 0;
    command = is_command(str);
    if (command)
        return 1;
    if (*stage == ROOMS && !is_room(str))
        *stage = TUNNELS;
    if (*stage == TUNNELS && !is_tunnel(str))
        return 0;
    if (*stage == ROBOTS && !is_robot(str))
        return 0;
    *stage = ROOMS;
    return 1;
}

char **read_input(void)
{
    char **buffer = my_allocarray(0);
    char *lineptr = NULL;
    enum input_stage stage = ROBOTS;

    while (my_readline(&lineptr) != -1 || my_strlen(lineptr) > 0) {
        if (!is_conforming(lineptr, &stage))
            break;
        if (!is_comment(lineptr))
            my_arrappend(&buffer, my_strdup(lineptr));
        free(lineptr);
    }
    free(lineptr);
    return buffer;
}
