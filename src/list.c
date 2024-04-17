/*
** EPITECH PROJECT, 2024
** list.c
** File description:
** Usual functions for linked lists
*/

#include <amazed.h>

list_t *create_list(void)
{
    list_t *list = NULL;

    return list;
}

list_t *create_node(void *data)
{
    list_t *list = malloc(sizeof(list_t));

    list->data = data;
    list->next = NULL;
    return list;
}

list_t *add_node(list_t **list, list_t *node)
{
    node->next = (*list);
    *list = node;
    return *list;
}

size_t my_listlen(list_t *list)
{
    size_t size = 0;

    while (list) {
        size++;
        list = list->next;
    }
    return size;
}

list_t *my_revlist(list_t *list)
{
    list_t *node;
    list_t *rev = create_list();

    while (list) {
        node = create_node(list->data);
        node->next = rev;
        rev = node;
        list = list->next;
    }
    return rev;
}
