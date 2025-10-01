#include <stdio.h>
#include <stdlib.h>

struct cellule{
    int valeur;
    struct cellule *suiv;
};
typedef struct cellule cellule;
typedef cellule *liste;
liste ajouetr_element(liste l ,int n){
    int v,i=0;
    liste t;
    do{
        printf("entrez la valeur %d à ajouter\n",i+1);
        scanf("%d",&v);
        t=(liste)malloc(sizeof(cellule));
        t->valeur=v;
        t->suiv=l;
        l=t;
        i++;
    } while (i<n);
    return l;
}
// Fonction pour afficher la liste
void afficher_liste(liste l) {
    printf("Liste : ");
    while (l != NULL) {
        printf("%d ", l->valeur);
        l = l->suiv;
    }
    printf("\n");
}
void supprimer_occurence(liste l){
    liste t;
    t=l;
    int v;
    printf("entrez l'element à supprimer\n");
    scanf("%d",&v);
    if (l==NULL){
        printf("la liste est vide on ne peut rien supprimer\n");
    }
    else if (t->suiv==NULL){
        if (t->valeur==v){
            free (t);
            t=NULL;
        }
        else{
            printf("l'element n'a pas été trouvé\n");
        }
    }
    else{
        liste a_sup=NULL;
        liste prec=NULL;
        do{
            if (prec==NULL && t->valeur==v){
                a_sup=t;
                l=t->suiv;
                t=t->suiv;
                free (a_sup);
            }
            
            else if (t->valeur==v){
                a_sup=t;
                prec->suiv=t->suiv;
                t=t->suiv;
                free(a_sup);
            }
            else{
                prec=t;
                t=t->suiv;
            }
            
            
        } while (t!=NULL);
        
    }
    
}

// Correction du main
int main() {
    liste l = NULL;
    int choix, n;
    do {
        printf("\nMenu :\n1. Ajouter des éléments\n2. Supprimer une occurrence\n3. Afficher la liste\n0. Quitter\nVotre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Combien d'éléments voulez-vous ajouter ? ");
                scanf("%d", &n);
                l = ajouetr_element(l, n);
                break;
            case 2:
                supprimer_occurence(l);
                break;
            case 3:
                afficher_liste(l);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide !\n");
        }
    } while (choix != 0);
    return 0;
}
