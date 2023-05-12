/*
    Klavyeden -1 girilene kadar girilen tek sayıları tek bağlı doğrusal bir listenin başına, girilen
    çift sayıları ise listenin sonuna ekleyen programı yazınız.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int number;
    struct Node *next;
} node;

void addNode(node**,int);
void printList(node*);

int main(){
    int num;
    node *head = NULL;
    
    while(1){

        printf("Enter number: ");
        scanf("%d", &num);
        
        if( num==-1 ) break;

        addNode(&head, num);
    }

    printList(head);

    return 0;
}
void addNode(node **head_ptr, int number){
    node *temp = (node *)malloc(sizeof(node));
    temp->number = number;

    if( *head_ptr==NULL || number%2==1 ){
        temp->next = *head_ptr;
        *head_ptr = temp;
    }
    else{
        node *iter = *head_ptr;
        while( iter->next != NULL )
            iter = iter->next;
        temp->next = iter->next;
        iter->next = temp;
    }
}
void printList(node *p){
    while( p != NULL ){
        printf("%d ", p->number);
        p = p->next;
    }
}