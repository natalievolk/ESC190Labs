#include <stdio.h>
#include <stdlib.h>

struct node{
    int data; 
    struct node *next; 
};
void printLinkedList(struct node *head){
    struct node *cur = head;
    while(cur->next != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("%d\n", cur->data);
}
int printListRec(struct node *head){
    struct node *cur = head;
    printf("%d ", cur->data);
    if(cur->next == NULL){
        printf("\n");
        return 0;
    }
    cur = cur->next;
    printListRec(cur);
}

struct node2{
    void *p_data; //a pointer to data (allocated with malloc)
    int type; // 0 if int, 1 if float, 2 if double
    struct node *next;
};

int print2(struct node2 *head){
    struct node2 *cur = head;
    
    if(cur->type == 0){
        int *value = cur->p_data;
        printf("%d ", *value);}
    else if(cur->type == 1){
        float *value2 = cur->p_data;
        printf("%f ", *value2);}
    else if(cur->type == 2){
        double *value3 = cur->p_data;
        printf("%f ", *value3);
    }
    if(cur->next == NULL){
        printf("\n");
        return 0;
    }
    cur = cur->next;
    print2(cur);
}

void appendInt(struct node2 *head, int *p_value){
    struct node2 *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node2 *node = (struct node2 *)malloc(sizeof(struct node2));
    cur->next = node;
    node->p_data = p_value;
    node->type = 0;
    node->next = NULL;
}
void appendFloat(struct node2 *head, float *p_value){
    struct node2 *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node2 *node = (struct node2 *)malloc(sizeof(struct node2));
    cur->next = node;
    node->p_data = p_value;
    node->type = 1;
    node->next = NULL;
}

void appendDouble(struct node2 *head, double *p_value){
    struct node2 *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node2 *node = (struct node2 *)malloc(sizeof(struct node2));
    cur->next = node;
    node->p_data = p_value;
    node->type = 2;
    node->next = NULL;
}

int main(){
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 3;

    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node0->next = node1;
    node1->data = 5;
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node1->next = node2;
    node2->data = 43;
    node2->next = NULL;
    printLinkedList(node0);
    printListRec(node0);


    struct node2 *node00 = (struct node2 *)malloc(sizeof(struct node2));
    node00->type = 0;
    int a = 3;
    node00->p_data = (int *)&a;
    
    struct node2 *node01 = (struct node2 *)malloc(sizeof(struct node2));
    node00->next = node01;
    float b = 5;
    node01->type = 1;
    node01->p_data = (int *)&b;
    
    struct node2 *node02 = (struct node2 *)malloc(sizeof(struct node2));
    node01->next = node02;
    double c = 2.7;
    node02->type = 2;
    node02->p_data = (double *)&c;

    node02->next = NULL;
    print2(node00);
    int value = 6;
    appendInt(node00, &value);
    float value2 = 7;
    appendFloat(node00, &value2);
    double value3 = 4.343;
    appendDouble(node00, &value3);
    print2(node00);
    //print2(node0);
    return 0;
}
