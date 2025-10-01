#include <stdio.h>
#include <stdlib.h>

// structure d'un noeud
struct Noeud {
    int donnee;
    struct Noeud *suivant;
    struct Noeud *precedent;
};

// creer un nouveau noeud
struct Noeud* creerNoeud(int val) {
    struct Noeud* nouveau = (struct Noeud*)malloc(sizeof(struct Noeud));
    nouveau->donnee = val;
    nouveau->suivant = nouveau;
    nouveau->precedent = nouveau; // pointe sur lui meme
    return nouveau;
}

// inserer au debut
struct Noeud* insererDebut(struct Noeud* tete, int val) {
    struct Noeud* nouveau = creerNoeud(val);
    
    if (tete == NULL) {
        return nouveau;
    }
    
    // on recupere le dernier noeud
    struct Noeud* dernier = tete->precedent;
    
    nouveau->suivant = tete;
    nouveau->precedent = dernier;
    tete->precedent = nouveau;
    dernier->suivant = nouveau;
    
    return nouveau; // le nouveau devient la tete
}

// inserer a la fin
struct Noeud* insererFin(struct Noeud* tete, int val) {
    struct Noeud* nouveau = creerNoeud(val);
    
    if (tete == NULL) {
        return nouveau;
    }
    
    struct Noeud* dernier = tete->precedent;
    
    nouveau->suivant = tete;
    nouveau->precedent = dernier;
    dernier->suivant = nouveau;
    tete->precedent = nouveau;
    
    return tete; // la tete reste la meme
}

// afficher dans le sens normal
void afficherAvant(struct Noeud* tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    struct Noeud* temp = tete;
    printf("Sens normal: ");
    do {
        printf("%d -> ", temp->donnee);
        temp = temp->suivant;
    } while (temp != tete);
    printf("(retour)\n");
}

// afficher dans le sens inverse
void afficherArriere(struct Noeud* tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    struct Noeud* temp = tete->precedent;
    printf("Sens inverse: ");
    do {
        printf("%d -> ", temp->donnee);
        temp = temp->precedent;
    } while (temp != tete->precedent);
    printf("(retour)\n");
}

int main() {
    struct Noeud* tete = NULL;
    int choix;
    int valeur;
    
    // menu principal
    while (1) {
        printf("\n====== MENU ======\n");
        printf("1. Inserer au debut\n");
        printf("2. Inserer a la fin\n");
        printf("3. Afficher (sens normal)\n");
        printf("4. Afficher (sens inverse)\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        
        if (choix == 1) {
            printf("Entrez la valeur: ");
            scanf("%d", &valeur);
            tete = insererDebut(tete, valeur);
            printf("Valeur inseree au debut!\n");
        }
        else if (choix == 2) {
            printf("Entrez la valeur: ");
            scanf("%d", &valeur);
            tete = insererFin(tete, valeur);
            printf("Valeur inseree a la fin!\n");
        }
        else if (choix == 3) {
            afficherAvant(tete);
        }
        else if (choix == 4) {
            afficherArriere(tete);
        }
        else if (choix == 0) {
            printf("Programme termine.\n");
            break;
        }
        else {
            printf("Erreur: choix invalide!\n");
        }
    }
    
    return 0;
}