#include <stdio.h> 
#include <stdlib.h>

/*
1. In your main function, define the variable int a and initialize it to 5.
   Now, write a function which does not return anything, but can set the value of 
   an integer to 10.
   
   Use this function to set the value of a to 10.
   
   Use printf to demonstrate that the value of a changed.
   
   Now, put a breakpoint at int a = 5, and trace the code.
   */

void f(int *p_a) {
    *p_a = 10;
}
/*
2. Implement a function that performs Insertion Sort https://en.wikipedia.org/wiki/Insertion_sort#Algorithm
   The function should take in an array of integers, and modify the array so that it's 
   sorted in increasing order.
  
   Here is code to print out an array of integers using a for-loop and a while-loop in C.

   int i = 0;
   int a[5] = {2, 3, 4, 5, 6};
   // initialize i to 0, run the loop while i < 5, and increase i by 1 every time;
   // Here, i++ is the same as i = i + 1
   for(i = 0; i < 5; i++){
       printf("%d\n", a[i]);
   }

   i = 0;
   while(i < 5){
       printf("%d\n", a[i]);
       i++; // same as i = i + 1
   }

   swap
   int temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;
   */
// [1, 3, 4, 5] --> 2 --> [1, 3, 4, 5, 2]

void insertSort(int list[], int size) {
    int *p_list = &list[0];
    for (int i = 1; i < size; i++) {
        int j = i-1;
        int temp = *(p_list + i);

        while (temp < *(p_list + j)) {
            *(p_list + j + 1) = *(p_list + j);
            *(p_list + j) = temp;

            j = j-1;
        }
    }
    
    int j = 0;
    for(j = 0; j < 6; j++){
       printf("%d ", list[j]);
    }
    // how to return the list??
}

int main() {
    int a = 5;
    printf("%d\n", a);
    f(&a);
    printf("%d\n", a);


    int b[6] = {1, 3, 2, 7, 2, 4};
    int size = sizeof(b)/4;
    insertSort(b, size);


    return 0;
}
