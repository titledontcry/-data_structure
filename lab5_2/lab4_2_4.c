#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;

node* newNode(int v) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = v;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void DisplayLL() {
    node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void doublyMaker() {
    if (head == NULL) return;
    node *curr = head;
    node *prev = NULL;
    while (curr != NULL) {
        curr->prev = prev;
        prev = curr;
        curr = curr->next;
    }
}
void reverseDisplay() {
    if (head == NULL) return;

    node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = n; i > 0; i--) {
        node *new_node = newNode(i);
        new_node->next = head;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
    }

    doublyMaker();
    reverseDisplay();

    return 0;
}
