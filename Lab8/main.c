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

int main() {
    printf("create bag");
    bag_t *bag = bag_create(compare_int);

    int n = 2;
    bag_insert(bag, &n);
    /*
    n=5;
    bag_insert(bag, &n);
    n=13;
    bag_insert(bag, &n);
    n=3;
    bag_insert(bag, &n);
    n=1;
    bag_insert(bag, &n);
    n=19;
    bag_insert(bag, &n);
    */

    printf("%d", is_avl_tree(bag));

    return 0;
}