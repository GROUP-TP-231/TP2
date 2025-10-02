#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int value;
    struct cell *next;
    struct cell *prev;
} cell;

void insert_head(cell **list) {
    int a;
    cell *temp = (cell*)malloc(sizeof(cell));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the value to insert at the head of the list: ");
    scanf("%d", &a);
    temp->value = a;
    if (*list == NULL) {
        temp->next = temp;
        temp->prev = temp;
        *list = temp;
    } else {
        temp->next = *list;
        temp->prev = (*list)->prev;
        (*list)->prev->next = temp;
        (*list)->prev = temp;
        *list = temp;
    }
}

void insert_tail(cell **list) {
    int a;
    cell *temp = (cell*)malloc(sizeof(cell));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the value to insert at the tail of the list: ");
    scanf("%d", &a);
    temp->value = a;
    if (*list == NULL) {
        temp->next = temp;
        temp->prev = temp;
        *list = temp;
    } else {
        temp->next = *list;
        temp->prev = (*list)->prev;
        (*list)->prev->next = temp;
        (*list)->prev = temp;
    
    }
}

void freelist(cell **list) {
    if (*list == NULL) return;
    cell *temp = *list;
    cell *start = temp;
    do {
        cell *next = temp->next;
        free(temp);
        temp = next;
    } while (temp != start);
    *list = NULL;
}

void displaylist(cell *list) {
    if (list == NULL) {
        printf("List is empty.\n");
        return;
    }
    cell *temp = list;
    do {
        printf("->%d", temp->value);
        temp = temp->next;
    } while (temp != list);
    printf("->\n");//Arrow at the begining and at the end is to indicate the tail follows the head so the list is circular
    printf("\n");
}
int main() {
    cell *list = NULL;
    int a;
    printf("Execution started... \n\n");
    while (1) {
        printf("*******MENU*******\n");
        printf("1-Insert a number at the head of the list\n");
        printf("2-Insert a number at the tail of the list\n");
        printf("3-Display list\n");
        printf("0-Exit code\n");
        printf("Choice: ");
        scanf("%d", &a);
        switch (a) {
            case 1:
                insert_head(&list);
                break;
            case 2:
                insert_tail(&list);
                break;
            case 3:
                displaylist(list);
                break;
            case 0:
                printf("Exiting...\n");
                freelist(&list);
                return 0;
            default:
                printf("Invalid choice. Try again...\n");
                break;
        }
    }
    return 0;
}