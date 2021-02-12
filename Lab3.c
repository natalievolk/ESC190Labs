#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
1. The function strcat in <string.h> appends a source string to a destination
   string. It returns the destination string. Write a version of the function
   char *my_strcat(char *dest, char *src)
*/
char *my_strcat(char *dest, char *src) {
    char *start = dest;
    while(*dest != '\0') {
        dest++;
    }
    while(*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}


/*
2. Write a recursive version of strcmp. The signature must be
   int my_strcmp_rec(char *str1, char *str2).
   The function should return 0 if the contents of str1 and str2
   are the same.
   If the contents of str1 and str2 are not the same, and the first
   character that doesn't match is at location i, the function
   should return str1[i]-str2[i].
   Each character corresponds to an integer value. For example,
   'A' corresponds to 65, 'B' corresponds to 66, ..., 'Z' 
   corresponds to 90, 'a' corresponds to 97, 'b' corresponds to
   98, ... 
   https://simple.wikipedia.org/wiki/ASCII#/media/File:ASCII-Table-wide.svg
   Returning the difference between the first pair of unmatched characters
   makes it so that strcmp returns a negative value if str1 comes before
   str2 in a lexicographic order.
*/
int my_strcmp_rec(char *str1, char *str2) {
    
    if(*str1 == '\0' && *str2 == '\0') {
        printf("%d\n", 0);
        return 0;
    } else if (*str1 != *str2) {
        //printf("%d\n", (int)*str1);
        //printf("%d\n", (int)*str2);
        printf("%d\n", (int)*str1 - (int)*str2);
        return ((int)*str1 - (int)*str2);
    } else {
        str1++;
        str2++;
        return my_strcmp_rec(str1, str2); //make sure to return
    }
}

/*
3. The C library function atoi converts a string to an integer. Write
   your own version of the function, with the signature
   int atoi(char *str)
   Hints:
   * The function isdigit (defined in <ctype.h>) can be used to tell if 
   a character is a digit
   * You can convert a digit c to an integer value using c-'0'
*/
int my_atoi(char *str) {
    int num = 0;
    //int counter = 1;
    while(*str != '\0') {
        if (isdigit(*str) == 0) {
            return 0;
        }
        num = num*10;
        num = num + (*str-'0');
        str++;
    }
    return (int)num;
}


/*
4. Implement Floyd's cycle-finding algorithm for a linked list in C
   https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare
   Your function should return 1 if there is a cycle in the linked list,
   and 0 otherwise. (Note that the linked code does more than that).

   Test your algorithm.
*/
struct node {
    int data;  
    struct node *next; 
};

int find_cycle(struct node *head) {
    struct node *tort = head;
    struct node *hare = head;

    while (hare->next != NULL) {
        tort = tort->next; 
        hare = hare->next;
        if (hare->next == NULL)  return 0;

        hare = hare->next;

        if (tort->data == hare->data)  return 1;
    }
    return 0;
}


int main() {
    //char *str1 = (char *)malloc(sizeof(char) * (20));
    char str1[6] = "Hello"; //6 may not work (not enough space to combine)
    char str2[10] = "He"; //use [] notation instead of char *str = ...
    printf("%s\n", strcat(str1, str2));
    //printf("%s\n", str1);

    char *str3 = "Hello";

    int result = my_strcmp_rec(str1, str2);
    printf("%d\n", result);

    char *str_num = "1234";
    //printf("%d\n", my_atoi(str_num));

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

    printf("%d\n", find_cycle(node0));
    */
    return 0;
}