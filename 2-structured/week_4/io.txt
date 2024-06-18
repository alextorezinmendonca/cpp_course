#include <stdio.h>
#include <stdlib.h>

//Print average and max value in external file
void printOutput(double *average, int *maxValue, FILE *outputFile){
    fprintf(outputFile, "The average value is: %f\n", *average);
    fprintf(outputFile, "The max value is: %d\n", *maxValue);
}


//Calculate max value and average from input pointer file
void calculateValue(FILE *ptr, int *maxValue, double *valueAverage){
    int index=0;
    int value, arraySize;
    double valueSum;

    while( fscanf(ptr, "%d", &value) != EOF){ //read until the end
        if(index != 0 ){ //if is first loop, the value is array size
            if(value > *maxValue){
                *maxValue = value; //Calculate max value iterative
            } 
            valueSum = valueSum + value; //calculate sum of all values
        }
        else{
            arraySize = value; //get array size from position 0 from input file
        }
        index++;
    }   
    *valueAverage = valueSum/arraySize; //calculate average
}


//Main function
int main(int argc, char *argv[]){

    //Initiate pointers
    double *valueAverage = (double *)malloc(sizeof(double));
    int *maxValue = (int *)malloc(sizeof(int));

    //Point to file initiate
    FILE *ptr;
    FILE *out;

    //Read/write file and store in pointer
    ptr = fopen(argv[1], "r+");
    out = fopen(argv[2], "w+");

    rewind(ptr);//Set the position to begin of file
    calculateValue(ptr, maxValue, valueAverage);
    printOutput(valueAverage, maxValue, out);
    printf("Value average is: %f\nMax value is: %d \n", *valueAverage, *maxValue);

    //Close input and output files
    fclose(ptr);
    fclose(out);

    return 0;
}

/*
From example input bellow:
6 10 980 30 70 30 10

The code give the output bellow:
Value average is: 188.333333
Max value is: 980

*/