#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **matriceCaracteresEnFichier() {
    char **matrice = NULL;
    printf("Saisir une caracteres a partir d'un fichier : \n");

    FILE* fichier = NULL;

    int nRow, nCol;
    fichier = fopen("matrice.txt", "r+");

    while(!feof(fichier)){
        fscanf(fichier, "%d\n", &nRow);
        fscanf(fichier, "%d\n", &nCol);
        printf("Nombre de ligne %d, nombre de columns %d\n", nRow, nCol);

        matrice = (char **)malloc(nRow * sizeof(char *));
        for(int i = 0; i < nRow; i++){
            matrice[i] = (char *)malloc(nCol * sizeof(char));
            for(int j = 0; j < nCol; j++){
                fscanf(fichier, "%s\n", &matrice[i][j]);
                printf("%c\t", matrice[i][j]);
            }
            printf("\n");
        }
    }
    fclose(fichier);

    printf("Afficher : \n");
    for(int i = 0; i < nRow; i++){
        for(int j = 0; j < nCol; j++){
            printf("Table[%d][%d] = %c\n", i, j, matrice[i][j]);
        }
    }

    return matrice;
}

int main() {
    char **matrice = matriceCaracteresEnFichier();


    return 0;
}