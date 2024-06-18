// Chalenge Option 01 (General)
// Use the linear linked list code to store a randomly generated set of 100 integers. 
// Now write a routine that will rearrange the list in sorted order of these values. 
// Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.
// How will this work? Compare two adjacent list elements and if they are out of order swap them. 
// After a first pass the largest element will have bubbled to the end of the list. Each pass can look at one less element as the end of a list stays sorted.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

//craete new struct to store linked list
typedef struct list
{
    int data;
    struct list *next; //point data value from struct recursivile to the same struct. So next has the same type of father struct.
} list;

//Check if linked list is empty
int is_not_empty(list *l){
    return (l!=NULL);
}

//Create new linked list
list* create_list(int d){
    list* head = malloc(sizeof(list)); //use malloc to reserve memory space at heap with list size to our new list.
    head->data = d; //Give initial int value
    head->next = NULL; //Point the first and only node to anywere. 
    return head;
}

//Add new integer to head of linked list and move the older head to the next position
list* add_to_front(int d, list *h){
    list* head = create_list(d);
    head->next = h; //point the new head->next to the older head pointer
    return head;
}

//Convert array to list
list* array_to_list(int d[], int size){

    //create new linked list as pointer
    list* head = create_list(d[0]);

    //loop index
    int i;

    //Add each value from array in linked list
    for(i = 1; i < size; i++){
        head = add_to_front(d[i], head);
    }
    return head;
}

//Print linked list
void print_list(list *h){
    int i = 1;
    while(is_not_empty(h)){
        printf("%d; ", h->data);
        h = h->next;
        i++;
        if(i == 6){
            i = 1;
            printf("\n\n");
        }
    }
}

//Random int generator based on min and max input
int randomGenerator(int minRange, int maxRange){
    return minRange + rand()% (maxRange + 1 - minRange);
}

//swap linked list values
void swap(list* p1, list* p2){
    int storeValue;
    storeValue = p1->data;
    p1->data = p2->data;
    p2->data = storeValue;

}

//Bubble sort algorith, to sort linked list in crescent order
int bubble_sort(list *h, int n){
    int change = 0, iterations = 0;
    list* headIte = h;

    while(1){
        headIte = h; //If not order, move the cursor to the first element and iterate again
        change = 0;

        while(is_not_empty(headIte->next)){
            if (headIte->data > headIte->next->data){ //If current data is bigger than the next, so swape
                swap(headIte, headIte->next);
                iterations++; 
                change++; //check if swapped value. If it occur soo the list is not sorted yet
            }
            headIte = headIte->next;
        }

        if(change == 0){//if any changes was made at this loop, linked list is order so return
            return iterations;
        }
    }
}

int main(){
    int minRange = 10, maxRange = 2000000; //min and max values for random genaretor
    int numberValue = 100; //Number of elements
    int i; //loop index
    int arrayValues[numberValue]; //array to store int value before to convert in linked list
    int ite;

    //Loop to genarete random in values
    for(i = 0; i < numberValue; i++){
        arrayValues[i] = randomGenerator(minRange, maxRange);
    }

    //Create linked list based on random values stored at array
    list *head = array_to_list(arrayValues, numberValue);

    //Printf linked list before sorter
    /*printf("!!Linked list in unsorted order!!\n");
      print_list(head);
    */

    //Sorte order at linked list
    ite = bubble_sort(head, numberValue);

    //Print linked list in sorted order
    printf("\n!!Linked list was order with %d iterations!!\n", ite);
    print_list(head);

    return 0;
}


