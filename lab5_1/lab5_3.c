#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct contact {
    char name[6];
    char number[11];
    struct contact *next;
};
//Create new node
struct contact* createNode(char name[],char number[]) {
    struct contact *new_node;
    new_node = (struct contact*)malloc(sizeof(struct contact));
    strcpy(new_node->name,name);
    strcpy(new_node->number,number);
    new_node->next = NULL;
    return new_node;
}

void searchList(struct contact* head, char name[]) {
    struct contact *ptr = head;
    while(ptr != NULL) {
        if(strcmp(ptr->name,name) == 0) {
            printf("%s 's number is %d",name,ptr->number);
            return;
        }
        ptr=ptr->next;
    }
    printf("Not found %s in the contact list\n",name);
}

//Hash function as shown in Chapter5
int hash2(char key[],int n) {
    int i,j=0;
    long long int hashVal = 0;

    for (i=strlen(key-1)-1; i>=0; i--) {
        hashVal+=key[i]*pow(32.0,j);
        j++;
    }
    return hashVal%n;
}
int main(){
    int i,n,k,m=13; //m is size of hash table
    struct contact *hash_table[m]; //array of pointer
    struct contact *new_node;
    //Use for transverse Linked List
    struct contact *ptr=NULL,*preptr=NULL;
    char name[6],number[11];
    for(i=0;i<m;i++) //initialize a chained hash table
        hash_table[i]=NULL;
    do{
        printf("=== Contact List ===\n");
        printf("1. Add new contact\n 2. Remove contact\n");
        printf("3. Search contact\n 4. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&n);
        if(n==1)
        {
            printf("Enter name:");
            scanf("%s",name);
            printf("Enter phone number:");
            scanf("%s",number);
            k = hash2(name,m);//call hash function
            printf("key:%s has hashkey=%d\n",name,k);
            new_node = createNode(name,number);
            new_node->next = hash_table[k];
            hash_table[k] = new_node;
            }
        else if(n==2)
        {
            printf("Enter name:");
            scanf("%s",name);
            k = hash2(name,m);
            //delete node
            ptr = hash_table[k];
            preptr = NULL;
            while(ptr!=NULL && strcmp(name,ptr->name) !=0 ) {
                preptr = ptr;
                ptr=ptr->next;
            }
            if (ptr == NULL) {
                printf("Node found %s in the contact list\n",name);
            } else {
                if (ptr==NULL) {
                    hash_table[k]=ptr->next;
                } else {
                    preptr->next=ptr->next;
                }
                free(ptr);
                printf("Deleted %s from the contact list\n",name);
            }
        }
        else if(n==3)
        {
            printf("Enter name:");
            scanf("%s",name);
            k = hash2(name,m);//call hash function
            searchList(hash_table[k],name);
        }
    }while(n!=4);
    //free memory
    return 0;
}