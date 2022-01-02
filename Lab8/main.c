/* FILE main.c
 *    Test the functionality of the avl_bag implementation.
 * Author: Francois Pitt, March 2012.
 */

/******************************************************************************
 *  Types and Constants.                                                      *
 ******************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bag.h"

int compare_int(bag_elem_t p1, bag_elem_t p2) {
    if ((int)(p1) > (int)(p2))
        return 1;
    else if ((int)(p1) < (int)(p2))
        return -1;
    else
        return 0;
}

void print_node(bag_elem_t elem) {
    printf("%d", *(int *)elem);
} 

int main() {

    bag_t *bag = bag_create(compare_int);

    int a0 = 2;
    bag_insert(bag, &a0);
    
    int a1=5;
    bag_insert(bag, &a1);
    int a2=13;
    bag_insert(bag, &a2);
    int a3=10;
    bag_insert(bag, &a3);

    /*
    bag_t *bag_norot = bag_create(compare_int);

    printf("%d\n", is_avl_tree(bag));

    int n0 = 7;
    bag_insert_norot(bag_norot, &n0);
    int n1 = 10;
    bag_insert_norot(bag_norot, &n1);
    int n2 = 5;
    bag_insert_norot(bag_norot, &n2);
    int n3 = 6;
    bag_insert_norot(bag_norot, &n3);
    int n4 = 9;
    bag_insert_norot(bag_norot, &n4);
    int n5 = 8;
    bag_insert_norot(bag_norot, &n5);
    printf("%d\n", is_avl_tree(bag_norot));
    return 0;
    */

    bag_print(bag, 3, print_node);
   
    bag_remove_2(bag, &a3);

    bag_print(bag, 3, print_node);
    
}