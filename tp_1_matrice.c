#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Cette fonction demande à l'utilisateur de saisir un tableau d'entiers
// et affiche le tableau
void tableauEntier() {
    int taille = 0;
    printf("Taille du tableau : ");
    scanf("%d", &taille);

    // Alloue de la mémoire pour le tableau
    int *table = (int*)malloc(taille * sizeof(int));

    // Demande à l'utilisateur de saisir chaque élément du tableau
    printf("Saisie des éléments du tableau :\n");
    for (int i = 0; i < taille; i++) {
        printf("Table[%d] = ", i);
        scanf("%d", &table[i]);
    }

    // Affiche le tableau
    printf("Affichage du tableau :\n");
    for (int i = 0; i < taille; i++) {
        printf("Table[%d] = %d\n", i, table[i]);
    }

    // Libère la mémoire allouée pour le tableau
    free(table);
}

void matriceEntier() {
    int tailleCol, tailleRow;
    printf("Nombre de lignes de la matrice : ");
    scanf("%d", &tailleRow);
    printf("Nombre de colonnes de la matrice : ");
    scanf("%d", &tailleCol);

    // Alloue de la mémoire pour chaque ligne de la matrice
    int **matrice = (int **)malloc(sizeof(int*) * tailleRow);

    // Demande à l'utilisateur de saisir chaque élément de la matrice
    printf("Saisie des éléments de la matrice :\n");
    for (int i = 0; i < tailleRow; i++) {
        matrice[i] = (int *)malloc(tailleCol * sizeof(int));
        for (int j = 0; j < tailleCol; j++) {
            printf("Matrice[%d][%d] = ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    // Affiche la matrice
    printf("Affichage de la matrice :\n");
    for (int i = 0; i < tailleRow; i++) {
        for (int j = 0; j < tailleCol; j++) {
            printf("Table[%d][%d] = %d\n", i, j, matrice[i][j]);
        }
    }

    // Libère la mémoire allouée pour chaque ligne de la matrice
    for (int i = 0; i < tailleRow; i++) {
        free(matrice[i]);
    }
    // Libère la mémoire allouée pour la matrice
    free(matrice);
}

void matriceCaracteres() {
    int nbLignes, nbColonnes;

    printf("Nombre de lignes de la matrice : ");
    scanf("%d", &nbLignes);
    printf("Nombre de colonnes de la matrice : ");
    scanf("%d", &nbColonnes);

    // Alloue de la mémoire pour chaque ligne de la matrice
    char **matrice = (char **)malloc(sizeof(char*) * nbLignes);

    printf("Saisie des éléments de la matrice :\n");
    // Demande à l'utilisateur de saisir chaque élément de la matrice
    for (int i = 0; i < nbLignes; i++) {
        matrice[i] = (char *)malloc(nbColonnes * sizeof(char));
        for (int j = 0; j < nbColonnes; j++) {
            printf("Table[%d][%d] = ", i, j);
            scanf("%s", &matrice[i][j]);
        }
    }

    printf("Affichage de la matrice :\n");
    // Affiche chaque élément de la matrice
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            printf("Table[%d][%d] = %s\n", i, j, &matrice[i][j]);
        }
    }

    // Libère la mémoire allouée pour chaque ligne de la matrice
    for (int i = 0; i < nbLignes; i++) {
        free(matrice[i]);
    }
    // Libère la mémoire allouée pour la matrice
    free(matrice);
}

int main() {
    // 1 - Saisir et afficher un tableau des entriers (dynamiquement)
    tableauEntier();

    // 2 - Saisir et afficher une matrice entiers
    matriceEntier();

    // 3 - Saisir et afficher une matrice de caracteres
    matriceCaracteres();
    
    return 0;
}