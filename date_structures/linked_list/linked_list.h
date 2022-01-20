/**
 * @file linked_list.h
 * @author ZiXyos
 * @brief
 * @version 0.1
 * @date 2022-01-20
 *
 * @copyright Copyright (c) 2022
 *
**/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linked_list_node {

    char *data;
    struct linked_list_node *next;
} linked_list_node_t;

typedef linked_list_node_t *linked_list_t;

bool list_isEmpty(linked_list_t list);
uint32_t list_get_size(linked_list_t list);
void list_dump(linked_list_t list);

bool list_add_elem_at_front(linked_list_t *list, char *data);
bool list_add_elem_at_back(linked_list_t *list, char *data);
bool list_add_elem_at_position(linked_list_t *list, char *data, uint32_t pos);

#endif /* LINKED_LIST_H */
