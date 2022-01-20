#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "linked_list.h"

bool list_isEmpty(linked_list_t list) {

    if (!list) return true;
    return false;
}

unsigned int list_get_size(linked_list_t list) {

    if (list_isEmpty(list)) return 0;

    unsigned int i = 0;
    linked_list_t tmp = malloc(sizeof(linked_list_t));
    if (!tmp) return 0;

    for (; list->next; i++) {

        tmp = (linked_list_t)list;
        list = (linked_list_t)list->next;
    }

    return i;
}

void list_dump(linked_list_t list) {

    if (list_isEmpty(list) || !list->data) return;

    linked_list_t node = list;
    for (; node; node = node->next)
        printf("%s\n", node->data);
}

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
    for (uint32_t i = 0; i != pos -1; i++) tmp = (linked_list_t)tmp->next;
    node->next = tmp->next;
    tmp->next = node;

    return true;
}

int main(int ac,char *const *av) {

    (void)ac;
    (void)av;

    linked_list_t *node = NULL;
    node = malloc(sizeof(linked_list_t));
    if (!node) return(-84);

    list_add_elem_at_front(node, "Hello");
    list_add_elem_at_back(node, "World");
    list_add_elem_at_back(node, "!");
    list_add_elem_at_position(node, "Bonjour", 1);

    printf("[Output]: size = %d\n", list_get_size(*node)) ;
    list_dump(*node);
}