/*
    Tek bağlı doğrusal listelerde listenin sonundaki düğümü keserek listenin başına ekleyen ve oluşan
    listenin son halini geri döndüren fonksiyonu yazınız.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int number;
    struct Node *next;
} node;

node *cutTailAddHead(node*);
void printList(node*);

int main(){

    node *head = malloc(sizeof(node));
    head->number = 1;
    node *iter = head;
    for(int i=0 ; i<5 ; i++){
        iter->next = malloc(sizeof(node));
        iter = iter->next;
        iter->number = i*10+1;
        iter->next = NULL;
    }

    printList(head);
    head = cutTailAddHead(head);
    printList(head);
   
    return 0;
}
node *cutTailAddHead(node *head){
    node *iter = head;
    while( iter->next->next!=NULL )
        iter = iter->next;
    iter->next->next = head;
    head = iter->next;
    iter->next = NULL;
    return head;
}
void printList(node *p){
    while( p != NULL ){
        printf("%d ", p->number);
        p = p->next;
    }
    printf("\n");
}