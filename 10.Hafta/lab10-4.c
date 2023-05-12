/*
    Tek bağlı doğrusal listede listenin sonundaki ve başındaki düğümün yerini değiştiren changeFirstAndLast isimli bir
    fonksiyon yazınız. (Fonksiyon parametre olarak bir liste alıp güncellenen listeyi geri döndürecektir.)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int number;
    struct Node *next;
} node;

node *changeFirstAndLast(node*);
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
    head = changeFirstAndLast(head);
    printList(head);

    return 0;
}
node *changeFirstAndLast(node *head){
    node *iter = head;
    while( iter->next->next!= NULL )
        iter = iter->next;
    node *temp;
    temp = iter->next;
    iter->next->next = head->next;
    iter->next = head;
    head->next = NULL;
    head = temp;
    return head;
}
void printList(node *p){
    while( p != NULL ){
        printf("%d ", p->number);
        p = p->next;
    }
    printf("\n");
}