/*
    Write C program to store information of students using structure. (In this example, you should store the information
    entered by the user using dynamic memory allocation.)
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char name[30];
    char surname[30];
    char ID[10];
} Student;
void printStudentInformation(Student*,int);
int main(){

    int i, n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student *students = malloc(n * sizeof(Student));

    if( !students ){
        printf("Memory cannot allocated!");
        exit(EXIT_FAILURE);
    }
    
    for(i=0 ; i<n ; i++){
        printf("Student %d\n", i+1);
        printf("Enter Name: ");
        scanf("%s", students->name);
        printf("Enter Surname: ");
        scanf("%s", students->surname);
        printf("Enter Student ID: ");
        scanf("%s", (students+i)->ID);
        printf("\n");
    }

    char ch;
    printf("Press [y] for print student informations: ");
    scanf(" %c", &ch);
    
    if( ch=='Y' || ch=='y' )
        printStudentInformation(students, n);

    free(students);

    return 0;
}
void printStudentInformation(Student *student, int size){
    for(int i=0 ; i<size ; i++){
        printf("Student %d\n", i+1);
        printf("Name and Surname: %s %s\n", (student+i)->name, (student+i)->surname);
        printf("Student ID: %s\n", (student+i)->ID);
    }
}
