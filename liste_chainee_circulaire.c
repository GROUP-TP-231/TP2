#include<stdio.h>
#include<stdlib.h>

typedef struct number{
    int nombre;
    struct number *suivant;
}*n;

n HEAD = NULL;
n QUEU = NULL;

struct number *ajouter_tete(n HEAD){
    n l = (n)malloc(sizeof(struct number));
    int v;
    printf("entrer la valeur a inserer en tete: ");
    scanf("%d", &v);
    l->nombre = v;
    if(HEAD== NULL){
        l->suivant = l;
        return l;
    }
    else{
        n temp = HEAD;
        while(temp->suivant != HEAD){
        temp = temp->suivant;
        }
        l->suivant = HEAD;
        temp->suivant = l;
        return l;
    }
}
struct number *ajouter_queu( n HEAD){
    int v;
    printf("entrer la valeur a inserer en queu de liste: ");
    scanf("%d",&v);
    struct number *li = malloc(sizeof(struct number));
    li->nombre = v;
    if(HEAD==NULL){
        li->suivant = li;
        li->suivant = HEAD;
        return HEAD;

    } 
    n temp = HEAD;
    while(temp->suivant !=HEAD){
        temp = temp->suivant;
    }
    temp->suivant = li;
    QUEU = li;
    QUEU->suivant =HEAD;
    return HEAD;  
}

void affichage(n HEAD){
    if(HEAD == NULL) return;
    n temp = HEAD;
    do {
        printf("%d-->>", temp->nombre);
        temp = temp->suivant;
    
} while(temp != HEAD);
printf("HEAD{%d}\n", HEAD->nombre);

}

int main(){
    int val;
    int i = 0, taille;
    printf("entrer le taille de la liste: ");
    scanf("%d", &taille);
    do {
        n p = (n)malloc(sizeof(struct number));
        printf("entrer la valeur %d: ", i+1);
        scanf("%d", &val);
        p->nombre = val;
        if(HEAD==NULL){
        HEAD = p;
        QUEU = p;
        p->suivant = HEAD;            
        }
        else{
            QUEU->suivant = p;
            QUEU = p;
            QUEU->suivant = HEAD;
        }
        i++;
    } while (i < taille);
    HEAD = ajouter_tete(HEAD);
    affichage(HEAD);
    HEAD= ajouter_queu(HEAD);
    affichage(HEAD);

}