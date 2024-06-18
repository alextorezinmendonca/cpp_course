/* Right linked list implementation + bubblesort algorithm for it */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ------------------------------- LINKED LIST CODE ------------------------------- */

/* Linked list node */
typedef struct node_t
{
    int data;
    struct node_t* next;

} node_t;


/* Function declarations */
node_t* create_node(int data);
int is_empty(const node_t* list);
int get_list_length(const node_t* list);
void add_to_back(int data, node_t** head);
void add_to_front(int data, node_t** head);
node_t* array_to_linked_list(const int* array, int size);
void swap_nodes(node_t** head, int idx_first, int idx_second);
void print_list(const node_t* head, int cols);

/* ------------------------------------- END -------------------------------------- */


/* ------------------------------- BUBBLE SORT CODE ------------------------------- */

/* Function declarations */
void bubblesort_linked_list(node_t** head);
void fill_array_with_random_numbers(int* arr, int size, int seed);

/* ------------------------------------- END -------------------------------------- */



int main()
{
    int arr[1000];
    int size = 1000;

    fill_array_with_random_numbers(arr, size, -1);

    node_t* head = array_to_linked_list(arr, size);

    printf("Unsorted lined list:\n");
    print_list(head, 5);
    
    bubblesort_linked_list(&head);

    printf("Sortd linked list:\n");
    print_list(head, 5);

    return 0;
}


/* ------------------------------- LINKED LIST CODE ------------------------------- */

/* Creates node for list and initializes it with given value - can be used to init completely new list */
node_t* create_node(int data)
{
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}


/* Checks if list is empty */
int is_empty(const node_t* list)
{
    return (list == NULL);
}


/* Returns list length */
int get_list_length(const node_t* list)
{
    int counter = 1;

    while (list->next != NULL)
    {
        list = list->next;
        counter++;
    }

    return counter;
}


/* Adds new element to the end of list pointed by head */
void add_to_back(int data, node_t** head)
{
    node_t* new_node = create_node(data);

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node_t* temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}


/* Adds new element to bottom of list pointed by head (replaces head) */
void add_to_front(int data, node_t** head)
{
    node_t* new_node = create_node(data);

    new_node->next = *head;
    *head = new_node;
}


node_t* array_to_linked_list(const int* array, int size)
{
    if (size == 0)
    {
        return NULL;
    }
    else
    {
        node_t* head = create_node(array[0]);

        for (int i=1; i<size; i++)
        {
            add_to_back(array[i], &head);
        }

        return head;
    }
}


/* Swaps nodes of give indexes in list pointed by head */
void swap_nodes(node_t** head, int idx_first, int idx_second)
{
    // If any of the idxs is larger than number of elements there is an error with inputs
    int list_length = get_list_length(*head);
    if ((idx_first >= list_length) || (idx_second >= list_length))
    {
        printf("Nodes swapping: wrong indexes provided: %d, %d.\n", idx_first, idx_second);
        return;
    }

    // Do nothing when indexes are the same
    if (idx_first == idx_second)
    {
        return;
    }

    node_t* pre_node1 = NULL;
    node_t* pre_node2 = NULL;
    node_t* node1 = *head;
    node_t* node2 = *head;
    node_t* temp;

    // Find nodes and nodes before them
    for (int i=0; i<idx_first; i++)
    {
        pre_node1 = node1;
        node1 = node1->next;
    }

    for (int i=0; i<idx_second; i++)
    {
        pre_node2 = node2;
        node2 = node2->next;
    }
    
    // Check if any of the nodes is head, if yes, make head point to the second node
    // Reattach next pointers of "pre" nodes
    if (pre_node1 == NULL)
    {
        *head = node2;
    }
    else
    {
        pre_node1->next = node2;
    }

    if (pre_node2 == NULL)
    {
        *head = node1;
    }
    else
    {
        pre_node2->next = node1;
    }

    // Reattach next poniters of "main" nodes
    temp = node2->next;
    node2->next = node1->next;
    node1->next = temp;
}


/* Prints whole list, cols argument says in how many columns to print (0 = no limits) */
void print_list(const node_t* head, int cols)
{
    int counter = 1;
    printf("start -> ");
    if (cols != 0) printf("\n");

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
        if ((cols != 0) && (counter++ == cols))
        {
            printf("\n");
            counter = 1;
        }
    }

    printf("end\n");
}


/* ------------------------------------- END -------------------------------------- */


/* ------------------------------- BUBBLE SORT CODE ------------------------------- */

/* Sorts given linked list with bubblesort algorithm */
void bubblesort_linked_list(node_t** head)
{
    node_t* temp = *head;
    int length = get_list_length(*head);
    int switched = 0;
    
    for (int i=0; i<length-1; i++)
    {
        for (int j=0; j<length-1-i; j++)
        {
            if (temp->next->data < temp->data)
            {
                swap_nodes(head, j, j+1);
                switched = 1;
            }
            else
            {
                temp = temp->next;
            }
        }
        temp = *head;

        if (switched == 0) break;
        switched = 0;
        
    }
}


/* Fills given array with "size" random numbers. If seed = -1, it is chosen by current time */
void fill_array_with_random_numbers(int* arr, int size, int seed)
{
    if (seed == -1)
    {
        seed = time(NULL);
    }

    srand(seed);

    for (int i=0; i<size; i++)
    {
        arr[i] = rand();
    }
}

/* ------------------------------------- END -------------------------------------- */
