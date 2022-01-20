
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list_node {

    char *data;
    struct linked_list_node *next;
} linked_list_node_t;

typedef linked_list_node_t *linked_list_t ;

#endif /* LINKED_LIST_H */
