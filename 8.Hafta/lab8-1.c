/*
    Define a struct named 'Student' for course attendance list of students. This struct consists of 'studentNumber', 'name',
    'surname' and 'midtermGrade' fields. Using this struct you defined, create a struct array for 10 students and get information
    of 3 students from the keyboard. Then, print the information of the students whose information was entered. 
*/
#include <stdio.h>
#define SIZE 10
typedef struct{
    char name[40];
    char surname[30];
    char studentNumber[15];
    float midtermGrade;
} Student;

int main(){

    Student students[SIZE];
    
    for(int i=0 ; i<3 ; i++){
        printf("Student %d\n", i+1);
        printf("Enter name: "); 
        scanf("%s", students[i].name);
        printf("Enter surname: "); 
        scanf("%s", students[i].surname);
        printf("Enter student number: ");
        scanf("%s", students[i].studentNumber);
        printf("Enter midterm grade: ");
        scanf("%f", &students[i].midtermGrade);
        printf("\n");
    }
    
    for(int i=0 ; i<3 ; i++)
        printf("Student %d\n"
               "Name and surname: %s %s\n"
               "Student number: %s\n"
               "Midterm grade: %.2f\n\n", i+1,
                                        students[i].name,
                                        students[i].surname,
                                        students[i].studentNumber,
                                        students[i].midtermGrade);

    return 0;
}