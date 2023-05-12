/*
    Tek bağlı doğrusal listede listenin başındaki düğümü keserek listenin sonuna ekleyen ve oluşan listenin
    son halini geri döndüren fonksiyonu yazınız.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int number;
    struct Node *next;
} node;

node *cutHeadAddTail(node*);
void printList(node*);

int main(){

    node *head = malloc(sizeof(node));
    head->number = 0;
    node *iter = head;
    for(int i=0 ; i<5 ; i++){
        iter->next = malloc(sizeof(node));
        iter = iter->next;
        iter->number = i*10+1;
        iter->next = NULL;
    }

    printList(head);
    head = cutHeadAddTail(head);
    printList(head);
    
    return 0;
}
node *cutHeadAddTail(node *head){
    node *iter = head;
    while( iter->next != NULL )
        iter = iter->next;
    iter->next = head;
    head = head->next;
    iter->next->next = NULL;
    return head;
}
void printList(node *p){
    while( p != NULL ){
        printf("%d ", p->number);
        p = p->next;
    }
    printf("\n");
}