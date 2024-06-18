//#define NDEBUG
#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int main(void){
    double x, y;
    while(1){
        printf("Type 2 floats:\n");
        scanf("%lf %lf", &x, &y);
        assert(y != 0);
        printf("when divid x/y = %lf\n", x/y);
    }
    return 0;
}