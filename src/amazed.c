/*
** EPITECH PROJECT, 2024
** amazed.c
** File description:
** Main file for amazed project
*/

#include <amazed.h>
#include <string.h>

bool_t rm_comments(char *line)
{
    size_t i = 0;

    while (line[i]) {
        while (line[i] && line[i] != '#')
            i++;
        if (!line[i])
            return 0;
        if ((line[i] == '#' && line[i + 1] != '#') ||
            (line[i] == '#' && line[i + 1] == '#' && line[i + 2] == '#')) {
            line[i] = '\0';
            return 1;
        }
        i += 2;
    }
    return 0;
}

static int get_robots(char **input)
{
    int nb_robots = 0;
    char **line = my_strsplit(input[0], " \t");

    nb_robots = my_strtoi(line[0]);
    my_freearray(line);
    my_putstr("#number_of_robots\n"),
    my_putnbr(nb_robots);
    my_putstr("\n");
    return nb_robots;
}

static void add_room(char *input, room_t ***rooms, enum room_type type)
{
    static size_t id = 0;
    room_t *room;
    char **line;

    line = my_strsplit(input, " \t");
    room = create_room(line[0], my_strtoi(line[1]), my_strtoi(line[2]));
    room->type = type;
    room->id = id;
    id++;
    print_room(room);
    my_arrappend(rooms, room);
    my_freearray(line);
}

static room_t **get_rooms(char **input)
{
    room_t **rooms = my_allocarray(0);
    enum room_type type = 0;

    my_putstr("#rooms\n");
    for (size_t i = 0; input[i]; i++) {
        type = NOTHING;
        if (my_strcmp(input[i], "##start") == 0) {
            my_putstr("##start\n");
            type = START;
            i++;
        }
        if (input[i] && my_strcmp(input[i], "##end") == 0) {
            my_putstr("##end\n");
            type = END;
            i++;
        }
        if (input[i] && is_room(input[i]))
            add_room(input[i], &rooms, type);
    }
    return rooms;
}

static void add_tunnel(char *line, matrix_t *links, room_t **rooms)
{
    size_t nb_rooms = my_arrlen(rooms);
    char **tokens;
    size_t from;
    size_t to;

    my_putstr(line);
    my_putstr("\n");
    tokens = my_strsplit(line, "- \t");
    for (size_t i = 0; i < nb_rooms; i++) {
        if (my_strcmp(rooms[i]->name, tokens[0]) == 0)
            from = i;
        if (my_strcmp(rooms[i]->name, tokens[1]) == 0)
            to = i;
    }
    links->values[from][to] = 1;
    links->values[to][from] = 1;
    my_freearray(tokens);
}

static matrix_t *get_links(char **input, room_t **rooms)
{
    size_t size = my_arrlen(rooms);
    matrix_t *links = create_matrix(size, size);

    for (size_t i = 0; input[i]; i++) {
        if (is_tunnel(input[i])) {
            my_putstr("#tunnels\n");
            break;
        }
    }
    for (size_t i = 0; input[i]; i++) {
        if (is_tunnel(input[i])) {
            add_tunnel(input[i], links, rooms);
        }
    }
    return links;
}

int amazed(void)
{
    char **input = read_input();
    int robots = 0;
    maze_t maze;
    int **paths;

    if (input[0] == NULL)
        return 84;
    robots = get_robots(input);
    maze.rooms = get_rooms(input);
    maze.links = get_links(input, maze.rooms);
    if (input_error(input) || positions_error(input) || no_room(input) ||
        no_pipe(input) || rooms_error(input) || non_existent_pipes(input))
        return 84;
    paths = find_shortest_path(&maze);
    if (my_arrlen(paths) == 0) {
        my_puterr("No path between start and end\n");
        return 84;
    }
    print_result(paths, maze.rooms, robots);
    return 0;
}
