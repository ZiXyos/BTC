/**
 * @file add_node.c
 * @author ZiXyos
 * @brief
 * @version 0.1
 * @date 2022-01-20
 *
 * @copyright Copyright (c) 2022
 *
**/

#include "linked_list.h"

bool list_add_elem_at_front(linked_list_t *list, char *data) {

    linked_list_t tmp = malloc(sizeof(linked_list_t));
    if (!tmp) return false;

    tmp->data = data;
    tmp->next = (*list);
    (*list) = tmp;

    return true;
}

bool list_add_elem_at_back(linked_list_t *list, char *data) {

    if(!data) return false;

    linked_list_t tmp = malloc(sizeof(linked_list_t));
    if (!tmp) return false;

    tmp->data = data;
    tmp->next = NULL;

    if(!list) {

        (*list) = tmp;
        return true;
    }

    linked_list_t last = (*list);
    while(last->next) last = (linked_list_t)last->next;

    last->next = tmp;
    return true;
}

bool list_add_elem_at_position(linked_list_t *list, char *data, uint32_t pos) {

    if (!data) return false;

    if (pos == 0) return list_add_elem_at_front(list, data);
    if (pos > list_get_size(*list)) return false;

    linked_list_t node = malloc(sizeof(linked_list_t));
    if (!node) return false;

    node->data = data;
    node->next = NULL;

    if (!list) {

        (*list) = node;
        return true;
    }

    linked_list_t tmp = (*list);
    for (uint32_t i = 0; i != pos -1; i++)
        tmp = (linked_list_t)tmp->next;

    node->next = tmp->next;
    tmp->next = node;

    return true;
}