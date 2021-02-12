#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

struct node{
    int data;
    struct node *next;
};

void print_linked_list(struct node *head);
void insert(struct node *head, int value);
void delete_value(struct node *head, int value);
void free_list(struct node *head);

#endif