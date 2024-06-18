// This program opens a file with integers reads the numbers 
// the first value is the lenght of data, the others are values for the data vector
// the program calculates the average value and the max value
// the output is saved on file and displayed on screen

#include<stdio.h>
#include<stdlib.h>

void read_data(FILE *input, int *data, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        fscanf(input, "%d", &data[i]);
    }
}

double average(int *d, int size)
{
    int i;
    double sum = 0.0; 
    for(i=0; i<size; i++)
    {
        sum += d[i];
    }
    return (sum / size);
}

int max_val(int *d, int size)
{
    int i;
    int max;
    max = d[0];
    for (i = 1; i < size; i++)
    {
        if (d[i] > max)
        {
            max = d[i];
        }
    }
    return (max);
}


void print_array(int *d, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");
}


int main()
    {
        FILE *input;
        FILE *output;
        int size;
        int *data;
        int max;
        double avg;
        // Input file
        input = fopen("myhw", "r");
        // getting the array size
        fscanf(input, "%d", &size);
        data = (int *)malloc(size * sizeof(int));
        // Reading the data
        read_data(input, data, size);
        print_array(data, size);
        max = max_val(data, size);
        avg = average(data, size);
        // Output file
        output = fopen("answer-hw3", "w");
        // Printing results on screen
        printf("Max: %d \n", max);
        printf("Average: %f \n", avg);
        // Printing results to file
        fprintf(output, "Max: %d \n", max);
        fprintf(output, "Average: %f \n", avg);
        return 0;
    }