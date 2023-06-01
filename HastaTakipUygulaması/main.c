#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_P_SIZE 100

typedef struct Patient{
    int p_no;
    char nameSurname[30];
    int age;
    char disease[30];
} Patient;

FILE *openfile(const char*);
void addPatient(const char*, FILE*);
void editPatient(const char*, FILE*);
void deletePatient(const char*, FILE*);
void searchPatient(const char*, FILE*);
void listPatients(const char*, FILE*);
void clearInput(void);

int main(void){

    int opt;
    const char *filename = "hastakayit.dat";
    
    FILE *fp = openfile(filename);
    if (!fp){
        fprintf(stderr, "Dosya acilamadi...");
        exit(EXIT_FAILURE);
    }

    while(1){

        system("cls");

        printf( "Hasta Ekle             [1]\n"
                "Hasta Guncelle         [2]\n"
                "Hasta Sil              [3]\n"
                "Hasta Ara              [4]\n"
                "Hastalari Listele      [5]\n\n"
                "Cikis                  [0]\n\n");
        
        opt = getch();
        
        switch(opt){
            case '1':
                addPatient(filename,fp);
                break;
            case '2':
                editPatient(filename,fp);
                break;
            case '3':
                deletePatient(filename,fp);
                break;
            case '4':
                searchPatient(filename,fp);
                break;
            case '5':
                listPatients(filename,fp);
                break;
            case '0':
                system("cls");
                fclose(fp);
                exit(EXIT_SUCCESS);
        }
    
    }
    
    return 0;
}

// Dosya yoksa oluşturur.
FILE *openfile(const char *filename){
    FILE *fp = fopen(filename,"r+");
    if (fp == NULL)
        if ((fp = fopen(filename,"w+")) == NULL)
            return NULL;
    return fp;
}
void addPatient(const char *filename, FILE *fp){
    system("cls");
    int i, n;
    printf("Eklenecek hasta sayisini giriniz: ");
    scanf("%d", &n); clearInput();
    system("cls");

    Patient control, *patients = (Patient *)malloc(n * sizeof(Patient));
    for(i=0 ; i<n ; i++){

        printf("Kayit %d\n", i+1);
        while(1){
            printf("Hastanin Numarasini Giriniz[1-%d]: ", MAX_P_SIZE);
            scanf("%d", &patients[i].p_no); clearInput();
            fseek(fp, sizeof(Patient)*(patients[i].p_no-1), SEEK_SET);
            fread(&control, sizeof(Patient), 1, fp);

            if (patients[i].p_no == control.p_no){
                printf("%d numarali hasta kaydi mevcut, farkli bir numara denemek icin bir tusa basiniz.\n", control.p_no);
                getch();
                system("cls");
            }
            else break;
        }
        printf("Hastanin Isim Soyismini Giriniz: ");
        fgets(patients[i].nameSurname, sizeof(patients[i].nameSurname), stdin);
        patients[i].nameSurname[strcspn(patients[i].nameSurname,"\n")] = '\0';
        printf("Hastanin Yasini Giriniz: ");
        scanf("%d", &patients[i].age); clearInput();
        printf("Hastaligini Giriniz: ");
        fgets(patients[i].disease, sizeof(patients[i].disease), stdin);
        patients[i].disease[strcspn(patients[i].disease,"\n")] = '\0';

        fseek(fp, sizeof(Patient)*(patients[i].p_no-1), SEEK_SET);
        fwrite(&patients[i], sizeof(Patient), 1, fp);
    }
}
void editPatient(const char *filename, FILE *fp){
    system("cls");
    int ch, p_no;
    Patient patient = {0};
    printf("Duzenlemek istediginiz hasta numarasini giriniz: ");
    scanf("%d", &p_no); clearInput();
    fseek(fp, sizeof(Patient)*(p_no-1), SEEK_SET);
    fread(&patient, sizeof(Patient), 1, fp);
    if (patient.p_no == 0){
        printf("%d numarasina ait kayitli bir hasta bulunmamaktadir.", p_no);
        getch();
    }
    else {
        system("cls");
        printf("Yeni Isim Soyisim Giriniz: ");
        fgets(patient.nameSurname, sizeof(patient.nameSurname), stdin);
        patient.nameSurname[strcspn(patient.nameSurname,"\n")] = '\0';
        printf("Yeni Yas Degeri Giriniz: ");
        scanf("%d", &patient.age); clearInput();
        printf("Yeni Hastalik Bilgisini Giriniz: ");
        fgets(patient.disease, sizeof(patient.disease), stdin);
        patient.disease[strcspn(patient.disease,"\n")] = '\0';
        fseek(fp, sizeof(Patient)*(p_no-1), SEEK_SET);
        fwrite(&patient, sizeof(Patient), 1, fp);
    }
}
void deletePatient(const char *filename, FILE *fp){
    system("cls");
    int p_no;
    Patient control, patient = {0};
    printf("Silinecek Olan Kayit Numarasini Giriniz: ");
    scanf("%d", &p_no); clearInput();
    fseek(fp, sizeof(Patient)*(p_no-1), SEEK_SET);
    fread(&control, sizeof(Patient), 1, fp);
    if (control.p_no == 0){
        printf("%d numarasina ait kayitli bir hasta bulunmamaktadir.", p_no);
    }
    else {
        fseek(fp, sizeof(Patient)*(p_no-1), SEEK_SET);
        fwrite(&patient, sizeof(Patient), 1, fp);
    }
}
void searchPatient(const char *filename, FILE *fp){
    system("cls");
    int p_no;
    Patient patient = {0};
    printf("Arama Yapmak Icin Hasta Numarasini Giriniz: ");
    scanf("%d", &p_no); clearInput();
    fseek(fp, sizeof(Patient)*(p_no-1), SEEK_SET);
    fread(&patient, sizeof(Patient), 1, fp);
    system("cls");
    if (patient.p_no == p_no)
        printf( "\xBA Hasta Numarasi:   %d\n"
                "\xBA Isim Soyisim:     %s\n"
                "\xBA Yas:              %d\n"
                "\xBA Hastalik:         %s\n", patient.p_no, patient.nameSurname, patient.age, patient.disease);
    else 
        printf("%d numarasina ait kayitli bir hasta bulunmamaktadir.", p_no);
    
    getch();
}
void listPatients(const char *filename, FILE *fp){
    system("cls");
    Patient patient = {0};
    printf("%-15s %30s %15s %30s\n\n", "Hasta Numarasi", "Isim Soyisim", "Yas", "Hastalik");
    fseek(fp, 0, SEEK_SET);
    while (fread(&patient, sizeof(Patient), 1, fp))
        if (patient.p_no != 0)
            printf("%-15d %30s %15d %30s\n", patient.p_no, patient.nameSurname, patient.age, patient.disease);

    getch();
}
void clearInput(void){
    while (getchar() != '\n');
}