 typedef struct Node {
    int data;
    struct Node* next;
 }Node;

 void supprimerOccurrences(Node**head,int val)  {
    Node *temp + *head, *prev = NULL;

    while (temp !=NULL) {
        if (temp->data == val){
            Node* asupprimer = temp;
            if (prev == NULL) *head = temp->next;
          
            else prev->next = temp->next;
            temp = temp->next;
            free(asupprimer);
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
 }