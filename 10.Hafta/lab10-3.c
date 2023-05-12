/*
    Tek bağlı doğrusal listenin ortasında yer alan elemanı silen bir fonksiyon yazınız.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int number;
    struct Node *next;
} node;

void delete_middleNode(node**);
void printList(node*);

int main(){

    node *head = malloc(sizeof(node));
    head->number = 1;
    node *iter = head;
    for(int i=0 ; i<4 ; i++){
        iter->next = malloc(sizeof(node));
        iter = iter->next;
        iter->number = i*10+1;
        iter->next = NULL;
    }
    printList(head);
    delete_middleNode(&head);
    printList(head);

    return 0;
}
void delete_middleNode(node **head_ptr){
    int i, size=0;
    node *iter = *head_ptr;
    while( iter != NULL ){
        iter = iter->next;
        size++;
    }
    iter = *head_ptr;
    for(i=0 ; i<size/2-1 ; i++)
        iter = iter->next;
    node *temp;
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
}
void printList(node *p){
    while( p != NULL ){
        printf("%d ", p->number);
        p = p->next;
    }
    printf("\n");
}