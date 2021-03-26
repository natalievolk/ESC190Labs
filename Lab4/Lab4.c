#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 1;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = 2;
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->data = 3;
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->data = 4;

    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    insert(node0, 10);
    delete_value(node0, 4);
    print_linked_list(node0);
    free_list(node0);
    //print_linked_list(node0);
    printf("%d", node0->data);
    return 0;
}