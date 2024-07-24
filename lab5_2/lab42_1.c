#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

node* newNode(int v) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = v;
    new_node->next = NULL;
    return new_node;
}
void DisplayLL() {
    node *ptr = head;
    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main() {
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    DisplayLL();

}
