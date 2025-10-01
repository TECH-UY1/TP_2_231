// ...existing code...
#include <stdio.h>
#include <stdlib.h>

struct cellule {
    int valeur;
    struct cellule *suiv;
};
typedef struct cellule cellule;
typedef cellule *liste;

liste ajouter_element_trie(liste l, int v) {
    liste t = (liste)malloc(sizeof(cellule));
    t->valeur = v;
    t->suiv = NULL;
    if (l == NULL || l->valeur > v) {
        t->suiv = l;
        return t;
    }
    liste p = l;
    while (p->suiv && p->suiv->valeur < v) {
        p = p->suiv;
    }
    t->suiv = p->suiv;
    p->suiv = t;
    return l;
}

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

void afficher_liste(liste l) {
    printf("Liste : ");
    while (l != NULL) {
        printf("%d ", l->valeur);
        l = l->suiv;
    }
    printf("\n");
}

void supprimer_occurence(liste l) {
    liste t = l;
    int v;
    printf("entrez l'element à supprimer\n");
    scanf("%d", &v);
    if (l == NULL) {
        printf("la liste est vide on ne peut rien supprimer\n");
    }
    else if (t->suiv == NULL) {
        if (t->valeur == v) {
            free(t);
            t = NULL;
        }
        else {
            printf("l'element n'a pas été trouvé\n");
        }
    }
    else {
        liste a_sup = NULL;
        liste prec = NULL;
        do {
            if (prec == NULL && t->valeur == v) {
                a_sup = t;
                l = t->suiv;
                t = t->suiv;
                free(a_sup);
            }
            else if (t->valeur == v) {
                a_sup = t;
                prec->suiv = t->suiv;
                t = t->suiv;
                free(a_sup);
            }
            else {
                prec = t;
                t = t->suiv;
            }
        } while (t != NULL);
    }
}

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
                supprimer_occurence(l);
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

