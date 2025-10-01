#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


Node* creernoeud(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insertionfin(Node** head, int data) {
    Node* newNode = creernoeud(data);

    
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;

    
    if (data < current->data) {
        newNode->next = current;
        current->prev = newNode;
        *head = newNode;
        return;
    }

    
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    // cas 3 : insertion ala fin
    if (current->next == NULL) {
        current->next = newNode;
        newNode->prev = current;
    } 
    // Cas 4 : Insertion au milieu
    else {
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

// Fonction d'affichage de la liste
void afficherList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Création d'une liste initiale triée
Node* creerlistinitiale() {
    Node* head = NULL;
    insertionfin(&head, 5);
    insertionfin(&head, 10);
    insertionfin(&head, 15);
    insertionfin(&head, 20);
    return head;
}

// Programme principal
int main() {
    Node* head = creerlistinitiale();
    int value;

    printf("Liste initiale :\n");
    afficherList(head);

    // Demander un élément à insérer
    printf("Entrez un entier à insérer : ");
    scanf("%d", &value);

    // Insertion de l'élément
    insertionfin(&head, value);

    printf("Liste après insertion de %d :", value);
    afficherList(head);

    return 0;
}
