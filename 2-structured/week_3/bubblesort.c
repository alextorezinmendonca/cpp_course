// Written by: Jascha Henseler
// Description: Bubble sort algorithm, generates a random list of 100 integers and sort them.
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Linked list data structure from lecture
typedef struct list
{
    int data;
    struct list *next;
} list; // typedef struct list;

int is_empty(const list *l) { return (l == NULL); }

// Create a linked list with one element and return a pointer to the head
list *create_list(int d)
{
    list *head = malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

// Function prints linked list
void print_list(list *h, char *title)
{
    printf("%s\n", title);
    int counter = 1;
    while (h != NULL)
    {
        printf("%12d |", h->data);
        h = h->next;
        if (counter % 5 == 0)
        {
            printf("\n");
        }
        counter++;
    }
}

// Create linked list by adding elements to the front.
list *add_to_front(int d, list *h)
{
    list *head = create_list(d);
    head->next = h;
    return head;
}

// Create linked list from array
list *array_to_list(int d[], int size)
{
    list *head = create_list(d[0]);
    int i;
    for (i = 1; i < size; i++)
    {
        head = add_to_front(d[i], head);
    }
    return head;
}

// Swap is helper function for the bubblesort function below
void swap(list *a, list *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Bubble sort algorithm for linked list data structure.
void bubblesort(list *h, int size)
{
    for (int i = 0; i < size; i++)
    {
        list *current = h;
        list *next = h->next;
        for (int j = 0; j < size - 1; j++)
        {
            if (current->data > next->data)
            {
                swap(current, next);
            }
            current = next;
            next = next->next;
        }
    }
}

int main()
{
    list *head = NULL;
    int data[100];
    // Fill the array with random integers
    for (int i = 0; i < 100; i++)
    {
        data[i] = rand();
    }

    head = array_to_list(data, 100);
    print_list(head, "100-element random list");
    printf("\n\n");
    printf("\\");
    bubblesort(head, 100);
    print_list(head, "100-element sorted list");
    printf("\n\n");

    return 0;
}

// // Output should be:
// 100-element random list
//    892053144 |   578354438 |  1807130337 |   884936716 |  1816731566 |
//   1269406752 |  1102246882 |   753799505 |   657821123 |   500782188 |
//   1908194298 |  2146319451 |  1557810404 |  1581030105 |  1351934195 |
//   1864546517 |  1478446501 |    34075629 |   269220094 |  1777724115 |
//   1654001669 |  1635339425 |   107554536 |  2020739063 |   997389814 |
//   1137623865 |  1962408013 |   595028635 |   824938981 |  1075260298 |
//    158374933 |  2035308228 |   194847408 |   571540977 |  1060806853 |
//   2118797801 |   685118024 |  1108728549 |  1083454666 |  1942727722 |
//    130060903 |  1952509530 |  1927702196 |  1044788124 |   357571490 |
//    771515668 |   590357944 |   510616708 |  1025921153 |  1646035001 |
//    937186357 |   585640194 |  1899894091 |  1356425228 |   156091745 |
//   1399125485 |  1617819336 |  1551901393 |  2110010672 |   530511967 |
//    784558821 |  2128236579 |  1624379149 |  1358580979 |   704877633 |
//   1580723810 |   101929267 |   563613512 |  1636807826 |  1954899097 |
//   1505795335 |   893351816 |  1404280278 |   197493099 |  1131570933 |
//   1817129560 |  1998097157 |  1264817709 |  1474833169 |   896544303 |
//    143542612 |   823378840 |    16531729 |  1441282327 |  1137522503 |
//    114807987 |    74243042 |  1784484492 |  1115438165 |   823564440 |
//   2007237709 |  1458777923 |  1457850878 |   101027544 |   470211272 |
//   1144108930 |   984943658 |  1622650073 |   282475249 |       16807 |

// 100-element sorted list
//        16807 |    16531729 |    34075629 |    74243042 |   101027544 |
//    101929267 |   107554536 |   114807987 |   130060903 |   143542612 |
//    156091745 |   158374933 |   194847408 |   197493099 |   269220094 |
//    282475249 |   357571490 |   470211272 |   500782188 |   510616708 |
//    530511967 |   563613512 |   571540977 |   578354438 |   585640194 |
//    590357944 |   595028635 |   657821123 |   685118024 |   704877633 |
//    753799505 |   771515668 |   784558821 |   823378840 |   823564440 |
//    824938981 |   884936716 |   892053144 |   893351816 |   896544303 |
//    937186357 |   984943658 |   997389814 |  1025921153 |  1044788124 |
//   1060806853 |  1075260298 |  1083454666 |  1102246882 |  1108728549 |
//   1115438165 |  1131570933 |  1137522503 |  1137623865 |  1144108930 |
//   1264817709 |  1269406752 |  1351934195 |  1356425228 |  1358580979 |
//   1399125485 |  1404280278 |  1441282327 |  1457850878 |  1458777923 |
//   1474833169 |  1478446501 |  1505795335 |  1551901393 |  1557810404 |
//   1580723810 |  1581030105 |  1617819336 |  1622650073 |  1624379149 |
//   1635339425 |  1636807826 |  1646035001 |  1654001669 |  1777724115 |
//   1784484492 |  1807130337 |  1816731566 |  1817129560 |  1864546517 |
//   1899894091 |  1908194298 |  1927702196 |  1942727722 |  1952509530 |
//   1954899097 |  1962408013 |  1998097157 |  2007237709 |  2020739063 |
//   2035308228 |  2110010672 |  2118797801 |  2128236579 |  2146319451 |