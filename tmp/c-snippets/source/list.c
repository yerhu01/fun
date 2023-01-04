/* Singly-linked list */
#include <stdlib.h>
#include <string.h>


/* Structure */
typedef struct slist_node {
    int data;
    struct slist_node *next;
} SListNode;

typedef struct slist {
    int size;
    struct slist_node *head, *tail;
} SList;


void slist_init(SList *list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return; 
}

int slist_insert_next(SList *list, SListNode *node, int data) {
    SListNode *new_node;
    
    if ((new_node = malloc(sizeof(SListNode)) == NULL)
        return -1;
    
    new_node->data = data; 
}

static void print_list() {
    
}

int main(int argc, char **argv) {
    SList list;
    slist_init(&list);

    
    return 0;
}
