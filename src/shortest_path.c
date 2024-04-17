/*
** EPITECH PROJECT, 2024
** shortest_path
** File description:
** get the shortest paths
*/

#include <amazed.h>

static void fill_dist(matrix_t *links, int *dist, size_t curr)
{
    for (size_t i = 0; i < links->nb_cols; i++) {
        if (links->values[curr][i] && dist[curr] + 1 < dist[i]) {
            dist[i] = dist[curr] + 1;
            fill_dist(links, dist, i);
            }
    }
}

static int get_previous_room(matrix_t *links,
    int *path, int *dist, size_t curr)
{
    int min_dist = __INT_MAX__;
    int min_id = -1;

    for (size_t i = 0; i < links->nb_cols; i++) {
        if (links->values[curr][i] && dist[i] < min_dist) {
            min_id = i;
            min_dist = dist[i];
        }
    }
    path[min_dist] = min_id;
    return min_id;
}

static int *get_path(matrix_t *links, int *dist, int start, int end)
{
    int temp;
    int *path;

    if (dist[end] == __INT_MAX__)
        return NULL;
    path = malloc(sizeof(int) * (dist[end] + 2));
    temp = end;
    path[dist[end]] = end;
    path[dist[end] + 1] = -1;
    while (temp != start) {
        temp = get_previous_room(links, path, dist, temp);
    }
    return path;
}

static int *find_new_path(int start, int end, maze_t *maze)
{
    int *path = NULL;
    int *dist = malloc(sizeof(int) * my_arrlen(maze->rooms));

    for (size_t i = 0; maze->rooms[i]; i++)
        dist[i] = __INT_MAX__;
    dist[start] = 0;
    fill_dist(maze->links, dist, start);
    path = get_path(maze->links, dist, start, end);
    return path;
}

static void update_links(matrix_t *links, int *path)
{
    size_t i = 0;

    if (path == NULL)
        return;
    while (path[i + 1] != -1) {
        links->values[path[i]][path[i + 1]] = 0;
        links->values[path[i + 1]][path[i]] = 0;
        i++;
    }
}

static int **find_all_distinct_paths(int start, int end, maze_t *maze)
{
    int **paths = my_allocarray(0);
    int *path;

    do {
        path = find_new_path(start, end, maze);
        update_links(maze->links, path);
        my_arrappend(&paths, path);
    } while (path != NULL);
    return paths;
}

int **find_shortest_path(maze_t *maze)
{
    int **paths;
    int start = 0;
    int end = 0;

    for (size_t i = 0; maze->rooms[i]; i++) {
        if (maze->rooms[i]->type == START)
            start = i;
        if (maze->rooms[i]->type == END)
            end = i;
    }
    paths = find_all_distinct_paths(start, end, maze);
    return paths;
}
