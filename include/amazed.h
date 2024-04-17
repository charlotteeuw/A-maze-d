/*
** EPITECH PROJECT, 2024
** amazed.h
** File description:
** Header file for amazed project
*/

#pragma once

#include <my_lib.h>

typedef struct list_s {
    void *data;
    struct list_s *next;
} list_t;

// list.c

list_t *create_list(void);
list_t *create_node(void *data);
list_t *add_node(list_t **list, list_t *node);
size_t my_listlen(list_t *list);
list_t *my_revlist(list_t *list);

enum input_stage {
    ROBOTS,
    ROOMS,
    TUNNELS,
};

enum room_type {
    NOTHING,
    START,
    END
};

typedef struct room_s {
    char *name;
    int x;
    int y;
    enum room_type type;
    size_t id;
} room_t;

// room.c

room_t *create_room(char *name, int posx, int posy);
int get_room_id(char *name, room_t **rooms);
void print_room(room_t *room);

typedef struct {
    size_t nb_cols;
    size_t nb_lines;
    int **values;
} matrix_t;

// matrix.c

matrix_t *create_matrix(size_t nb_cols, size_t nb_lines);

typedef struct tunnel_s {
    room_t *from;
    room_t *to;
} tunnel_t;

typedef struct maze_s {
    matrix_t *links;
    room_t **rooms;
} maze_t;

int amazed(void);
int positions_error(char **input);
int rooms_error(char **input);
int input_error(char **input);
int no_room(char **input);
int no_pipe(char **input);
int non_existent_pipes(char **input);
bool_t rm_comments(char *line);
char **read_input(void);
int **find_shortest_path(maze_t *maze);
void print_result(int **paths, room_t **rooms, int robots);
int my_put_nbr(int nb);

// line_type.c

bool_t is_comment(const char *str);
bool_t is_command(const char *str);
bool_t is_tunnel(const char *str);
bool_t is_room(const char *str);
bool_t is_robot(const char *str);
