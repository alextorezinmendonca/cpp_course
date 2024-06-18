# include <stdio.h>
# include <math.h>
int main(void){
    for(double i =0.1; i<0.9; i+=0.1){
        printf("Sine(%f) is %f\n\n", i, sin(i));
    }
    return 0;
}
