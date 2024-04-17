/*
** EPITECH PROJECT, 2024
** pipes_error.c
** File description:
** error checking for pipes
*/

#include <amazed.h>
#include <string.h>

static char **parse_tunnel(char *input)
{
    char **line = my_strsplit(input, " \t-");
    char **tunnel = malloc(sizeof(char *) * 3);

    tunnel[0] = line[0];
    tunnel[1] = line[1];
    tunnel[2] = NULL;
    return tunnel;
}

static int check_tunnel_error(char **tunnel, char **rooms)
{
    int from = 0;
    int to = 0;

    for (size_t i = 0; rooms[i] != NULL; i++) {
        if (my_strcmp(tunnel[0], rooms[i]) == 0)
            from++;
        if (my_strcmp(tunnel[1], rooms[i]) == 0)
            to++;
    }
    my_freearray(tunnel);
    if (from == 1 && to == 1)
        return 0;
    return 1;
}

int non_existent_pipes(char **input)
{
    char **rooms = my_allocarray(0);
    char **line;

    for (size_t i = 0; input[i]; i++) {
        if (is_room(input[i])) {
            line = my_strsplit(input[i], " \t");
            my_arrappend(&rooms, my_strdup(line[0]));
            my_freearray(line);
        }
    }
    for (size_t i = 0; input[i]; i++) {
        if (is_tunnel(input[i]) &&
            check_tunnel_error(parse_tunnel(input[i]), rooms)) {
            my_puterr("Pipe from/to room that does not exist\n");
            return 84;
        }
    }
    return 0;
}
