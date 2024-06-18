#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert node at the end of the list
Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        return newNode;
    }
    
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Bubble sort for linked list
void bubbleSort(Node* start) {
    int swapped;
    Node* ptr;
    Node* lptr = NULL;

    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr = start;

        while (ptr->next != lptr) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;

    } while (swapped);
}

// Display linked list
void display(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp) {
        printf("%d ", temp->data);
        count++;
        if (count % 5 == 0) {
            printf("\n");
        }
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    int i;

    // Seed for random values
    srand(time(0));

    // Insert 100 random integers
    for (i = 0; i < 100; i++) {
        head = insert(head, rand() % 1000); // random numbers between 0 and 999
    }

    printf("Original List:\n");
    display(head);
    printf("\n");

    bubbleSort(head);

    printf("Sorted List:\n");
    display(head);

    return 0;
}
