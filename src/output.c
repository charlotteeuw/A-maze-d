/*
** EPITECH PROJECT, 2024
** output.c
** File description:
** display output
*/

#include <amazed.h>

static void print_move(int robot, char *room)
{
    my_putchar('P');
    my_put_nbr(robot + 1);
    my_putchar('-');
    my_putstr(room);
}

static void print_tick(int **paths, room_t **rooms, int robots, int *arrived)
{
    static int tick = 1;
    size_t nb_paths = my_arrlen(paths);
    bool_t print_space = FALSE;
    int robot_progress = tick;

    for (int robot = 0; robot < robots; robot++) {
        robot_progress = tick - robot / nb_paths;
        if (arrived[robot] || robot_progress <= 0)
            continue;
        if (print_space)
            my_putchar(' ');
        print_space = TRUE;
        print_move(robot,
            rooms[paths[robot % nb_paths][robot_progress]]->name);
        if (paths[robot % nb_paths][robot_progress + 1] == -1)
            arrived[robot] = 1;
    }
    my_putchar('\n');
    print_space = FALSE;
    tick++;
}

void print_result(int **paths, room_t **rooms, int robots)
{
    int *arrived = malloc(sizeof(int) * robots);
    bool_t nb_arrived = 0;

    for (int i = 0; i < robots; i++)
        arrived[i] = 0;
    my_putstr("#moves\n");
    while (nb_arrived != robots) {
        nb_arrived = 0;
        print_tick(paths, rooms, robots, arrived);
        for (int i = 0; i < robots; i++)
            nb_arrived += arrived[i];
    }
}
