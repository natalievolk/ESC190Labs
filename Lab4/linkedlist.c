#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void print_linked_list(struct node *head)
{
    while(head){
        printf("%d\n", head->data);
        head = head->next;
    }
}

void insert(struct node *head, int value){
    while (head->next != NULL) {
        head = head->next;
    }
    
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    
    head->next = new_node;
    
    new_node->data = value;
    new_node->next = NULL;
    
}

void delete_value(struct node *head, int value){
    struct node *cur = head;

    while ((cur->next)->data != value){
       cur = cur->next;
    }
    struct node *delete = cur->next;
    cur->next = (cur->next)->next;
    free(delete);
}

void free_list(struct node *head){
    struct node *cur = head;
    while (cur->next != NULL && (cur->next)->next != NULL) {
        
        struct node *delete = cur->next;
        cur->next = (cur->next)->next;
        free(delete);
    }
    free(head);
}