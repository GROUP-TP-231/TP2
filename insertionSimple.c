#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data >=wwwwwwwwwwwwwww data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL && temp->next->data < data)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, x;
    printf("Entrez le nombre d'elements : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertSorted(&head, x);
    }
    printf("Liste triee : ");
    printList(head);
    return 0;
}