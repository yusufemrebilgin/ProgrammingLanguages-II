#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX_STUDENT_NO 100

typedef struct Student{
    int studentID;
    char nameSurname[30];
    char department[30];
    struct Student *next;
} Student;

FILE *openfile(const char *);
void addStudent(FILE *);
void updateStudent(FILE *);
void deleteStudent(FILE *);
void searchStudent(FILE *);
void listStudents(FILE *);
void fileToLinkedList(FILE *);
void clearInput(void);

int main(){

    int opt;
    const char *filename = "ogrencikayit.dat";
    
    FILE *fp;
    if ((fp = openfile(filename)) == NULL){
        printf("Dosya Acilamadi...");
        exit(EXIT_FAILURE);
    }

    while(1){

        system("cls");
        printf( "Ogrenci Kayit Ekle       [1]\n"
                "Ogrenci Kayit Guncelle   [2]\n"
                "Ogrenci Kayit Sil        [3]\n"
                "Ogrenci Kayit Ara        [4]\n"
                "Ogrenci Kayit Listele    [5]\n"
                "Kayitlari Listeye Ekle   [6]\n\n"
                "Cikis                    [0]\n\n" );

        switch (opt = getch()){
            case '1':
                addStudent(fp);
                break;
            case '2':
                updateStudent(fp);
                break;
            case '3':
                deleteStudent(fp);
                break;
            case '4':
                searchStudent(fp);
                break;
            case '5':
                listStudents(fp);
                break;
            case '6':
                fileToLinkedList(fp);
                break;
            case '0':
                system("cls");
                fclose(fp);
                exit(EXIT_SUCCESS);
        }
    }
    return 0;
}
FILE *openfile(const char *filename){
    FILE *fp = fopen(filename,"r+");
    if (!fp)
        if (!(fp = fopen(filename,"w+")))
            return NULL;
    return fp;
}
void addStudent(FILE *fp){
    system("cls");
    int i, n;
    printf("Eklenecek Olan Ogrenci Sayisini Giriniz: ");
    scanf("%d", &n);
    Student control, *student = (Student *)malloc(n * sizeof(Student));
    for(i=0 ; i<n ; i++){
        while(1){
            system("cls");
            printf("Ogrenci %d\n", i+1);
            printf("Ogrenci Numarasini Giriniz [1-%d]: ", MAX_STUDENT_NO);
            scanf("%d", &student[i].studentID); clearInput();
            fseek(fp, sizeof(Student)*(student[i].studentID-1), SEEK_SET);
            fread(&control, sizeof(Student), 1, fp);
            if (control.studentID == student[i].studentID){
                printf("%d numarasina ait kayit bulunuyor farkli bir numara denemek icin herhangi bir tusa basiniz.\n", student[i].studentID);
                getch();     
            }
            else break;
        }
        printf("Ogrenci Isim Soyismini Giriniz: ");
        fgets(student[i].nameSurname, sizeof(student[i].nameSurname), stdin);
        student[i].nameSurname[strcspn(student[i].nameSurname,"\n")] = '\0';
        printf("Ogrenci Bolumunu Giriniz: ");
        fgets(student[i].department, sizeof(student[i].department), stdin);
        student[i].department[strcspn(student[i].department,"\n")] = '\0';
        fseek(fp, sizeof(Student)*(student[i].studentID-1), SEEK_SET);
        fwrite(&student[i], sizeof(Student), 1, fp);
    }
    free(student);
}
void updateStudent(FILE *fp){
    system("cls");
    int s_id;
    Student student = {0};
    printf("Guncellemek Istediginiz Ogrenci Numarasini Giriniz: ");
    scanf("%d", &s_id); clearInput();
    fseek(fp, sizeof(Student)*(s_id-1), SEEK_SET);
    fread(&student, sizeof(Student), 1, fp);
    if (student.studentID == s_id){
        system("cls");
        printf("Yeni Isim Soyisim Giriniz: ");
        fgets(student.nameSurname, sizeof(student.nameSurname), stdin);
        student.nameSurname[strcspn(student.nameSurname,"\n")] = '\0';
        printf("Yeni Bolum Giriniz: ");
        fgets(student.department, sizeof(student.department), stdin);
        student.department[strcspn(student.department,"\n")] = '\0';
        fseek(fp, sizeof(Student)*(student.studentID-1), SEEK_SET);
        fwrite(&student, sizeof(Student), 1, fp);
    }
    else{
        printf("%d numarasina ait kayit bulunmamaktadir, devam etmek icin herhangi bir tusa basiniz.", s_id);
        getch();
    }
}
void deleteStudent(FILE *fp){
    system("cls");
    int s_id;
    Student control, student = {0};
    printf("Silmek Istediginiz Ogrencinin Numarasini Giriniz: ");
    scanf("%d", &s_id); clearInput();
    fseek(fp, sizeof(Student)*(s_id-1), SEEK_SET);
    fread(&control, sizeof(Student), 1, fp);
    if (control.studentID == 0){
        printf("%d numarasina ait kayit bulunmamaktadir, devam etmek icin herhangi bir tusa basiniz.", s_id);
        getch();
    }
    else{
        fseek(fp, sizeof(Student)*(s_id-1), SEEK_SET);
        fwrite(&student, sizeof(Student), 1, fp);
    }
}
void searchStudent(FILE *fp){
    system("cls");
    int s_id;
    Student student = {0};
    printf("Aramak Istediginiz Ogrenci Numarasini Giriniz: ");
    scanf("%d", &s_id); clearInput();
    fseek(fp, sizeof(Student)*(s_id-1), SEEK_SET);
    fread(&student, sizeof(Student), 1, fp);
    system("cls");
    if (student.studentID == s_id)
        printf( "Ogrenci Numarasi: %d\n"
                "Isim Soyisim:     %s\n"
                "Bolum:            %s\n", student.studentID, student.nameSurname, student.department);
    else 
        printf("Aradiginiz numaraya (%d) ait kayit bulunmamaktadir.", s_id);
        getch();
}
void listStudents(FILE *fp){
    system("cls");
    Student student = {0};
    printf("%-17s %30s %30s\n\n", "Ogrenci Numarasi", "Isim Soyisim", "Bolum");
    rewind(fp);
    while (fread(&student, sizeof(Student), 1, fp))
        if (student.studentID != 0)
            printf("%-17d %30s %30s\n", student.studentID, student.nameSurname, student.department);
    
    getch();
}
void fileToLinkedList(FILE *fp){
    system("cls");
    Student student, *head, *p;
    fseek(fp, 0, SEEK_SET);
    p = (Student *)malloc(sizeof(Student));
    head = p;
    while (fread(p, sizeof(Student), 1, fp))
        if (p->studentID != 0){
            p->next = (Student *)malloc(sizeof(Student));
            p = p->next;
            p->next = NULL;
        }    
    
    p = head;
    while (p->next!= NULL){
        printf("%-12d %30s %30s\n", p->studentID,p->nameSurname,p->department);
        p = p->next;
    }
    getch();
    free(p);
    free(head);
}

void clearInput(void){
    while (getchar() != '\n');
}