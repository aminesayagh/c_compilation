#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void tableauEntier(){
    int taille = 0;

    printf("Taille du tableau : ");
    scanf("%d", &taille);

    // declaration
    int *table = (int*)malloc(taille * sizeof(int));

    // saisir
    for(int i = 0; i < taille; i++) {
        printf("Table[%d] = ", i);
        scanf("%d", &table[i]);
    }

    // afficher
    for(int i = 0; i < taille; i++) {
        printf("Table[%d] = %d\n", i, table[i]);
    }

    free(table);
}

void matriceEntier() {
    int tailleCol, tailleRow;

    printf("Nombre de Lignes : ");
    scanf("%d", &tailleRow);

    printf("Nombre de colonnes : ");
    scanf("%d", &tailleCol);

    int **matrice = (int **)malloc(sizeof(int*) * tailleRow);

    printf("Saisir : \n");

    for(int i = 0; i < tailleRow; i++){
        matrice[i] = (int *)malloc(tailleCol * sizeof(int));

        for(int j = 0; j < tailleCol; j++){
            printf("Matrice[%d][%d] = ", i, j);
            scanf("%d", &matrice[i][j]);

        }
    }

    printf("Afficher : \n");

    for(int i = 0; i < tailleRow; i++){
        for(int j = 0; j < tailleCol; j++){
            printf("Table[%d][%d] = %d\n", i, j, matrice[i][j]);
        }
    }

    for(int i = 0; i < tailleRow; i++){
        free(matrice[i]);
    }
    free(matrice);
}

void matriceCaracteres() {
    int tailleCol, tailleRow;

    printf("Nombre de Lignes : ");
    scanf("d", &tailleRow);

    printf("Nombre de colonnes : ");
    scanf("d", &tailleCol);

    char **matrice = (char **)malloc(sizeof(char*) * tailleRow);

    printf("Saisir : \n");
    for(int i = 0; i < tailleRow; i++){
        matrice[i] = (char *)malloc(tailleCol * sizeof(char));

        for(int j = 0; j < tailleCol; j++){
            printf("Table[%d][%d] = ", i, j);
            scanf("%s", &matrice[i][j]);
        }
    }

    printf("Afficher : \n");
    for(int i = 0; i < tailleRow; i++){
        for(int j = 0; j < tailleCol; j++){
            printf("Table[%d][%d] = %s\n", i, j, &matrice[i][j]);
        }
    }

    for(int i = 0; i < tailleRow; i++){
        free(matrice[i]);
    }
    free(matrice);
}

void matriceCaracteresEnFichier() {
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

    for(int i = 0; i < nRow; i++){
        free(matrice[i]);
    }
    free(matrice);
}

int main() {
    // 1 - Saisir et afficher un tableau des entriers (dynamiquement)
    tableauEntier();

    // 2 - Saisir et afficher une matrice entiers
    matriceEntier();

    // 3 - Saisir et afficher une matrice de caracteres
    matriceCaracteres();

    // 4 - Saisir et afficher une matrice de caracteres a partir d'un fichier
    matriceCaracteresEnFichier();
    
    return 0;
}