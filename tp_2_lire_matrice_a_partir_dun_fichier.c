#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Cette fonction lit une matrice de caractères à partir d'un fichier et la renvoie
char **matriceCaracteresEnFichier() {
    char **matrice = NULL;
    printf("Lecture d'une matrice de caractères à partir d'un fichier : \n");

    // Ouvre le fichier en lecture
    FILE* fichier = fopen("matrice.txt", "r+");

    int nRow, nCol;
    // Lit les dimensions de la matrice du fichier
    fscanf(fichier, "%d\n", &nRow);
    fscanf(fichier, "%d\n", &nCol);
    printf("Nombre de lignes : %d, nombre de colonnes : %d\n", nRow, nCol);

    // Alloue de la mémoire pour chaque ligne de la matrice
    matrice = (char **)malloc(nRow * sizeof(char *));
    for (int i = 0; i < nRow; i++) {
        matrice[i] = (char *)malloc(nCol * sizeof(char));

        // Lit chaque caractère du fichier et le stocke dans la matrice
        for (int j = 0; j < nCol; j++) {
            fscanf(fichier, "%s\n", &matrice[i][j]);
            printf("%c\t", matrice[i][j]);
        }
        printf("\n");
    }

    // Ferme le fichier
    fclose(fichier);

    // Affiche la matrice lue à partir du fichier
    printf("Affichage de la matrice : \n");
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            printf("Table[%d][%d] = %c\n", i, j, matrice[i][j]);
        }
    }

    return matrice;
}

int main() {
    // Lit la matrice à partir du fichier
    char **matrice = matriceCaracteresEnFichier();

    return 0;
}