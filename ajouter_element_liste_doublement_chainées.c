#include <stdio.h>
#include <stdlib.h>


// Définition d'une cellule pour liste doublement chaînée
struct cellule {
    int valeur;
    struct cellule *suiv;
    struct cellule *prec;
};
typedef struct cellule cellule;
typedef cellule *liste;
// Ajout trié dans une liste doublement chaînée
liste ajouter_element_trie(liste l, int v) {
    liste t = (liste)malloc(sizeof(cellule));
    t->valeur = v;
    t->suiv = NULL;
    t->prec = NULL;
    if (l == NULL || l->valeur > v) {
        t->suiv = l;
        if (l) l->prec = t;
        return t;
    }
    liste p = l;
    while (p->suiv && p->suiv->valeur < v) {
        p = p->suiv;
    }
    t->suiv = p->suiv;
    t->prec = p;
    if (p->suiv) p->suiv->prec = t;
    p->suiv = t;
    return l;
}
// Affichage de la liste doublement chaînée
void afficher_liste(liste l) {
    printf("Liste : ");
    while (l) {
        printf("%d ", l->valeur);
        l = l->suiv;
    }
    printf("\n");
}
// Suppression d'une occurrence dans une liste doublement chaînée
liste supprimer_occurence(liste l, int v) {
    liste t = l;
    while (t) {
        if (t->valeur == v) {
            if (t->prec) t->prec->suiv = t->suiv;
            else l = t->suiv;
            if (t->suiv) t->suiv->prec = t->prec;
            free(t);
            break;
        }
        t = t->suiv;
    }
    return l;
}
// Tri par sélection pour liste doublement chaînée
liste trier_liste(liste l) {
    if (!l) return l;
    for (liste p = l; p; p = p->suiv) {
        liste min = p;
        for (liste q = p->suiv; q; q = q->suiv) {
            if (q->valeur < min->valeur) min = q;
        }
        int tmp = p->valeur;
        p->valeur = min->valeur;
        min->valeur = tmp;
    }
    return l;
}
// Nouveau main pour tester la liste doublement chaînée
int main() {
    liste l = NULL;
    int choix, v;
    do {
        printf("\nMenu :\n1. Ajouter un élément trié\n2. Trier la liste\n3. Afficher la liste\n4. Supprimer une occurrence\n0. Quitter\nVotre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Valeur à ajouter : ");
                scanf("%d", &v);
                l = ajouter_element_trie(l, v);
                break;
            case 2:
                l = trier_liste(l);
                printf("Liste triée !\n");
                break;
            case 3:
                afficher_liste(l);
                break;
            case 4:
                printf("Valeur à supprimer : ");
                scanf("%d", &v);
                l = supprimer_occurence(l, v);
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
