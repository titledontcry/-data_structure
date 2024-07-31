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
bool isCircular(node *h) {
    if (h == NULL) {
        return 0;
    }
    node *move_1 = head;
    node *move_2 = head;
    while (move_2 != NULL && move_2->next != NULL) {
        move_1 = move_1->next;
        move_2 = move_2->next->next;
        if (move_1 == move_2) {
            return true;
        }
    }
    return false;
}
int main() {
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    if (!isCircular(head)) {
        node *last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = head;
    }
    DisplayLL();
    if (isCircular(head)) {
        printf("this LL is circular\n");
    } else {
        printf("this LL isn't circular\n");
    }
    return 0;
}
