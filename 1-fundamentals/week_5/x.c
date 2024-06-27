#include <stdio.h>

int main(void){

    const int SIZE = 5;
    int grade[] = {10, 20 , 30, 40, 50};
    double sum = 0.0;
    double *ptr = &sum;
    int i = 0;

    printf("grade");

    for(i; i < SIZE; i++)
        printf("%d\n",grade[i]);
    i = 0;
    for(i; i < SIZE; i++){
        printf("%d\t\a",grade[i]);
        sum = sum + grade[i];
    }
        
    printf("AVG is %.2f\n\n", sum/SIZE);

    printf("sum is %p, %lu %4.10lf %f\n", ptr, ptr, *ptr, *ptr);
    printf("grades are at %lu to %lu\n\n", grade, grade+5); 

    return 0;
}