/*
* list.h
*/

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/* Structure */
struct slist_node {
    int data;
    struct slist_node *next;
};

struct slist {
    int size;
    struct slist_node *head, *tail;
};

/* Public Interface */
void slist_init();
void slist_destroy();
int slist_insert_after();

#endif
