/*
    Write C program to store data in structures dynamically. (In this example, you should to store the information
    entered by the user using dynamic memory allocation.)
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct{
    char nickname[20];
    char email[40];
    char *password;
} User;

void getUserData(User*,int);
void getPassword(User*,int);
void printUserData(User*,int);

int main(){

    int n;
    printf("Enter the number of users: ");
    scanf("%d", &n);

    User *users = malloc(n * sizeof(User));
    if( !users ){
        printf("Memory cannot allocated!");
        exit(EXIT_FAILURE);
    }    

    getUserData(users, n);
    printUserData(users,n);
    
    for(int i=0 ; i<n ; i++)
        free(users[i].password);
    free(users);

    return 0;
}
void getUserData(User *user, int size){
    for(int i=0 ; i<size ; i++){
        printf("User %d\n", i+1);
        printf("Enter nickname: ");
        scanf("%s", user[i].nickname);
        printf("Enter email address: ");
        scanf("%s", user[i].email);
        printf("Enter password: ");
        getPassword(&user[i], 12);
        printf("\n\n");
    }
}
void getPassword(User *user, int maxLength){
    char ch;
    int i = 0;
    user->password = malloc((maxLength+1) * sizeof(char));
    if( user->password==NULL ){
        printf("Memory cannot allocated!");
        exit(EXIT_FAILURE);
    }
    while((ch=getch()) != 13 && i<maxLength+1 ){
        user->password[i++] = ch;
        printf("*");
    }
    user->password[i] = '\0';
}
void printUserData(User *user, int size){
    for(int i=0 ; i<size ; i++){
        printf("User-%d Nickname: %s\n", i+1, user[i].nickname);
        printf("User-%d Email: %s\n\n", i+1, user[i].email);
    }
}