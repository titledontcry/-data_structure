#include<stdio.h>
#include<stdlib.h>
#define Size 7

struct  node
{
    int data;
    struct node *next;
};
struct node *hash_table[Size];   //array of pointer

void insertChain(int value)
{
    struct node *new_node;
    new_node= (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next=NULL;

    int key = value%Size;

    if(hash_table[key] == NULL) {
        hash_table[key] = new_node;
    } else {
        struct node *temp = hash_table[key];
        while(temp->next != NULL) {
            temp = temp -> next;
        }
        temp->next = new_node;
    }
}

void printChain()
{
    for (int i = 0; i < Size; i++) {
        struct node *temp = hash_table[i];
        printf("chain[%d]", i);
        while (temp != NULL) {
            printf("-->%d",temp->data);
            temp=temp->next;
        }
        printf("-->NULL\n");
    }
}


int main()
{
    int i;

    for(i=0;i<Size;i++)     //initialize a chained hash table
        hash_table[i]=NULL;

    insertChain(15);
    insertChain(22);
    insertChain(95);
    insertChain(56);
    insertChain(12);
    insertChain(27);
    insertChain(63);
    printChain();


    return 0;
}
