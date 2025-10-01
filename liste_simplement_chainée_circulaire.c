#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Création d'un nouveau nœud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = newNode; // au départ il pointe sur lui-même
    return newNode;
}

// Insertion en tête
Node* insertHead(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode; // premier élément
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode; 
    return newNode; // le nouveau devient la tête
}

// Insertion en queue
Node* insertTail(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head; // la tête ne change pas
}

// Affichage de la liste
void display(Node* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(retour à %d)\n", head->data);
}

// Programme principal
int main() {
    Node* head = NULL;
    int choix, valeur;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("Entrez la valeur à insérer en tête : ");
                scanf("%d", &valeur);
                head = insertHead(head, valeur);
                break;
            case 2:
                printf("Entrez la valeur à insérer en queue : ");
                scanf("%d", &valeur);
                head = insertTail(head, valeur);
                break;
            case 3:
                display(head);
                break;
            case 0:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide !\n");
        }
    } while (choix != 0);

    return 0;
}