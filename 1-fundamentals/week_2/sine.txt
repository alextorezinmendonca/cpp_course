#include <stdio.h>
#include <math.h>

int main(void){
	
 double inputValue;

 printf("Type value betwen 0 and 1: ");
 scanf("%lf", &inputValue);

 if(inputValue > 0 && inputValue < 1)
 { 
  double sinResult = sin(inputValue); //Calculate sin and store in double variable
  printf("Sine of this value is: %lf\n\n", sinResult);
 } 
 else
 {
  printf("The value is out of range\n\n");
 }

 return 0;
}
