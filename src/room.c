/*
** EPITECH PROJECT, 2024
** room.c
** File description:
** Useful functions for rooms
*/

#include <amazed.h>

room_t *create_room(char *name, int posx, int posy)
{
    room_t *room = malloc(sizeof(room_t));

    room->name = my_strdup(name);
    room->x = posx;
    room->y = posy;
    return room;
}

int get_room_id(char *name, room_t **rooms)
{
    int i = 0;

    while (rooms[i] && my_strcmp(rooms[i]->name, name)) {
        i++;
    }
    if (!rooms[i])
        return -1;
    return i;
}

void print_room(room_t *room)
{
    my_putstr(room->name);
    my_putstr(" ");
    my_put_nbr(room->x);
    my_putstr(" ");
    my_put_nbr(room->y);
    my_putstr("\n");
}
