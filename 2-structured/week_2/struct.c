#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum department{HR = 1, Sales, Research, Software} department;
typedef struct people{
                        department job; 
                        int salary;
                        unsigned secNumber;
                    } people;

int minSalary[4] = {2000, 3500, 5000, 5200};
int maxSalary[4] = {9000, 30000, 18000, 22000};
int minSecNumber = 1000;
int maxSecNumber = 99999;
int minDepartmentNum = 1;
int maxDepartmentNum = 4;

//Function to generate randon values between limited range
int randomGenerator(int minRange, int maxRange){
    return minRange + rand() % (maxRange + 1 - minRange);
}

//Funcion to get deparmentNumber referenced enum and convert in to string value
const char* getDepartmentName(enum department departmentNumber){
    switch (departmentNumber)
    {
    case HR: return "HR"; break;
    case Sales: return "Sales"; break;
    case Research: return "Research"; break;
    case Software: return "Software"; break;
    default:
        break;
    }
}


void printEmployData(people personData){
    //Get deparment name and print
    printf("Department name is: %s  |  ", getDepartmentName(personData.job));

    //print salary
    printf("the salary is: %d BRL  |  ", personData.salary);

    //print security number
    printf("and the security number is: %d\n\n", personData.secNumber);
}


void main(){

    struct people peopleInformation[10];
    int departmentPeople = 0;

    //Atribute the values
    for(int i = 0; i < 10; i++){
        //Define people deparment based on random between 1(HR) and 4(Software)
        departmentPeople = randomGenerator(minDepartmentNum, maxDepartmentNum);
        peopleInformation[i].job = departmentPeople;
        
        //Define salary between range defined at minSalary and maxSalary based on deparment chosed before
        peopleInformation[i].salary = randomGenerator(minSalary[departmentPeople], maxSalary[departmentPeople]);

        //Define new secNumber based on random number between defined range
        peopleInformation[i].secNumber = randomGenerator(minSecNumber, maxSecNumber);

        //Function to print employ data
        printEmployData(peopleInformation[i]);
    }
}