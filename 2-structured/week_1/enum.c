#include <stdio.h>

enum day{sun, mon, tue, wed, thu, fri, sat};

void print_day(enum day d){

	switch(d){

		case sun: printf("sunday"); break;
		case mon: printf("monday"); break;
	        case tue: printf("tuesday"); break;
		case wed: printf("wednesday"); break;
	        case thu: printf("thurday"); break;
	        case fri: printf("friday"); break;
	        case sat: printf("saturday"); break;
		default: printf("%d the are an error", d);

	}

}
enum day next_day(enum day d){

	return (d + 1 );
}

int main(){

	enum day today = fri;
	printf("%d", fri);
	print_day(today);
	printf("\n\n");
	print_day(3);
	printf("\n\n");
	print_day(next_day(today));
	printf("\n\n");
	return 0;

}

