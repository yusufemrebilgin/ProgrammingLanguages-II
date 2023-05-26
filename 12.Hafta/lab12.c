#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Student{
    int studentID;
    char name[60];
    float midtermGrade;
    float finalGrade;
    float average;
} Student;

void menu(void);
void createFile(void);
void addStudentRecord(void);
void listStudentRecord(void);
float showAverage(void);

int main(){
    menu();
    return 0;
}
void menu(){

    int opt;
    createFile();

    while(1){
        system("cls");
        printf( "Ogrenci Kayit Ekle                [1]\n"
                "Ogrenci Kayit Listele             [2]\n"
                "Ortalamayi Goster                 [3]\n"
                "Cikis                             [0]\n\n");

        switch( opt = getch() ){
            case '1':
                addStudentRecord();
                break;
            case '2':
                listStudentRecord();
                break;
            case '3':
                system("cls");
                printf("Average: %.2f", showAverage());
                getchar();
                break;
            case '0':
                system("cls");
                exit(EXIT_SUCCESS);
        }
    }
}
// Dosya yoksa oluşturur.
void createFile(){
    FILE *fp;
    if( (fp = fopen("ogrenciler.dat", "r")) == NULL )
        if( (fp = fopen("ogrenciler.dat", "w")) == NULL ){
            printf("Dosya olusturulamadi...");
            exit(EXIT_FAILURE);
        }
    fclose(fp);
}    
void addStudentRecord(){
    system("cls");
    FILE *fp = fopen("ogrenciler.dat", "a");
    if (!fp){
        printf("Dosya Acilamadi...");
        exit(EXIT_FAILURE);
    }
    Student student;
    printf("Ogrenci Numarasini Giriniz: ");
    scanf("%d", &student.studentID);
    printf("Ogrenci Ismini Giriniz: ");
    scanf("%s", student.name);
    printf("Ogrenci Vize Notunu Giriniz: ");
    scanf("%f", &student.midtermGrade);
    printf("Ogrenci Final Notunu Giriniz: ");
    scanf("%f", &student.finalGrade);
    student.average = 0.4 * student.midtermGrade + 0.6 * student.finalGrade;

    fprintf(fp, "%d %s %f %f %f\n",student.studentID,student.name,student.midtermGrade,student.finalGrade,student.average);

    fclose(fp);
}
void listStudentRecord(){
    system("cls");
    FILE *fp = fopen("ogrenciler.dat", "r");
    if (!fp){
        printf("Dosya acilamadi...");
        exit(EXIT_FAILURE);
    }
    Student temp;

    printf("%-15s %30s %8s %8s %10s\n\n", "Ogrenci Numara", "Isim", "Vize", "Final", "Ortalama");
    fscanf(fp, "%d%s%f%f%f",&temp.studentID,temp.name,&temp.midtermGrade,&temp.finalGrade,&temp.average);
    
    while (!feof(fp)){

        printf("%-15d %30s %8.2f %8.2f %10.2f\n",temp.studentID,temp.name,temp.midtermGrade,temp.finalGrade,temp.average);
        fscanf(fp, "%d%s%f%f%f",&temp.studentID,temp.name,&temp.midtermGrade,&temp.finalGrade,&temp.average);

    }    
    fflush(stdin);
    getchar();
    fclose(fp);
}
float showAverage(){
    system("cls");
    int studentCounter = 0;
    float sum = 0.0;
    FILE *fp = fopen("ogrenciler.dat", "r");
    if (!fp){
        printf("Dosya Acilamadi...");
        exit(EXIT_FAILURE);
    }
    Student temp;
    while (!feof(fp)){
        fscanf(fp, "%d%s%f%f%f",&temp.studentID,temp.name,&temp.midtermGrade,&temp.finalGrade,&temp.average);
        studentCounter++;
        sum += temp.average;
    }
    fclose(fp);
    return sum/studentCounter;
}