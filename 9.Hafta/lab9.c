#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct Student{
    char name[50];
    int studentNumber;
    float midtermGrade;
    float finalGrade;
    float average;
    struct Student *next;
} node;
void addStudent(void);
void showGrades(void);
void updateStudent(void);
void showAverage(void);
void showBestStudent(void);
void menu(void);

node *head = NULL;

int main(){

    menu();
   
    return 0;
}

//Düğümü öğrenci numarasına göre uygun olan yere ekler.
void addStudent(){
    
    int i, size;
    system("cls");
    printf("Enter the number of students: ");
    scanf("%d", &size);
    for(i=0 ; i<size ; i++){

        node *p = head, *temp = (node *)malloc(sizeof(node));

        if(!temp){
            perror("Memory cannot allocated");
            exit(EXIT_FAILURE);
        }
        system("cls");
        printf("Student %d\n\n", i+1);
        printf("Enter Student Name: ");
        scanf("%s", temp->name);
        printf("Enter Student Number: ");
        scanf("%d", &temp->studentNumber);
        printf("Enter Midterm Grade: ");
        scanf("%f", &temp->midtermGrade);
        printf("Enter Final Grade: ");
        scanf("%f", &temp->finalGrade);
        temp->average = 0.4 * temp->midtermGrade + 0.6 * temp->finalGrade;

        if(head == NULL || temp->studentNumber < head->studentNumber){
            temp->next = head;
            head = temp;
        }
        else{
            while(p->next != NULL && temp->studentNumber > p->next->studentNumber)
                p = p->next;
            temp->next = p->next;
            p->next = temp;
        }
    }
}
void showGrades(){

    system("cls");
    node *p = head;
    printf("%-14s %30s %14s  %12s  %10s\n\n", "Student Number", "Student Name", "Midterm Grade", "Final Grade", "Average");
    while( p != NULL ){
        printf("%-14d %30s %14.2f %12.2f %10.2f\n", p->studentNumber, p->name, p->midtermGrade, p->finalGrade, p->average);
        p = p->next;
    }
    getch();
}
void updateStudent(){
    node *p = head;
    int s_number;
    char ch;
    system("cls");
    printf("%-15s %30s\n\n", "Student Number", "Student Name");
    while( p != NULL ){
        printf("%-15d %30s\n", p->studentNumber, p->name);
        p = p->next;
    }
    printf("\n\nEnter the student's number to be updated: ");
    scanf("%d", &s_number);
    p = head;
    while( p != NULL ){
        if( p->studentNumber == s_number ){
            system("cls");
            printf("\xBA Current Student Number: %d\n", p->studentNumber);
            printf("\xBA Enter New Student Number: ");
            scanf("%d", &p->studentNumber);
            printf("\xBA Current Student Name: %s\n", p->name);
            printf("\xBA Enter New Student Name: ");
            scanf("%s", p->name);
            printf("\xBA Current Midterm Grade: %.2f\n", p->midtermGrade);
            printf("\xBA Enter New Midterm Grade: ");
            scanf("%f", &p->midtermGrade);
            printf("\xBA Current Final Grade: %.2f\n", p->finalGrade);
            printf("\xBA Enter New Final Grade: ");
            scanf("%f", &p->finalGrade);
            p->average = 0.4 * p->midtermGrade + 0.6 * p->finalGrade;
            break;
        }
        p = p->next;
    }
}
void showAverage(){
    node *p = head;
    int i=0;
    float avg = 0.0;
    while(p != NULL){
        avg += p->average;
        p = p->next;
        i++;
    }
    if (avg>0.0) avg /= i;
    system("cls");
    printf("\xDB\xB3 Average: %.2f", avg);
    getch();
}
void showBestStudent(){
    node *temp = head, *bestStudent=head;
    
    while( temp != NULL ){
        if( bestStudent->average < temp->average )
            bestStudent = temp;
        temp = temp->next;
    }
    system("cls");
    printf("\xDB\xBA Student Number:  %d\n", bestStudent->studentNumber);
    printf("\xDB\xBA Student Name:    %s\n", bestStudent->name);
    printf("\xDB\xBA Midterm Grade:   %.2f\n", bestStudent->midtermGrade);
    printf("\xDB\xBA Final Grade:     %.2f\n", bestStudent->finalGrade);
    printf("\xDB\xBA Average:         %.2f\n\n", bestStudent->average);
    getch();
}
void menu(){
    char ch;
    while(1){
        system("cls");
        printf("\xDB\xB3 Add Student                        [1]\n"
               "\xDB\xB3 Show Student Grades                [2]\n"
               "\xDB\xB3 Update Student                     [3]\n"
               "\xDB\xB3 Show Average                       [4]\n"
               "\xDB\xB3 Show The Most Successful Student   [5]\n\n"
               "\xDB\xB3 Press [0] for exit.");
        
        switch( ch=getch() ){
            case '1':
                addStudent(); 
                break;
            case '2':
                showGrades();
                break;
            case '3':
                updateStudent(); 
                break;
            case '4':
                showAverage();
                break;
            case '5':
                showBestStudent();
                break;
            case '0':
                exit(EXIT_SUCCESS);
        }
    }
}
