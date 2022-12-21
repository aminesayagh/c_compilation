#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 100


int *saisirEntiers(int taille) {
    int *table = malloc(taille*sizeof(int));

    for(int i = 0; i < taille; i++){
        printf("Table[%d] = ", i);
        scanf("%d", &table[i]);
    }

    return table;
}

void afficherEntiers(int *table, int taille) {
    for(int i = 0; i < taille; i++){
        printf("Table[%d] = %d\n", i, table[i]);
    }
}

void exercice1() {
    // 1- Saisir un tableau des entier (dynamique) avant de l’afficher.
    printf("1- Afficher Tableau des enties\n");

    int taille = 0;
    printf("Taille du tableau : ");
    scanf("%d", &taille);
    int *table = saisirEntiers(taille);
    afficherEntiers(table, taille);
    
    free(table);
}

int **saisirMatrice(int row, int col){
    int **table = malloc(row*sizeof(int*));
    printf("Saisir : \n");
    
    for(int i = 0; i < row; i++){
        table[i] = (malloc(col*sizeof(int)));
        for(int j = 0; j < col; j++){
            printf("Table[%d][%d] : ", i, j);
            scanf("%d",&table[i][j]);
        }
    }
    
    return table;
}

void afficherMatrice(int **table, int row, int col){
    printf("Affichage : \n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("Table[%d][%d] : %d\n", i, j, table[i][j]);
        }
    }
}

void exercice2() {
    // 2- Saisir une matrice des entiers avant de l’afficher
    printf("2- Saisir une matrice des entiers\n");
    
    int tailleCol, tailleRow;
    
    printf("Nombre de Lignes: ");
    scanf("%d", &tailleRow);
    
    printf("Nombre de Colomuns: ");
    scanf("%d", &tailleCol);
    
    int **table = saisirMatrice(tailleRow, tailleCol);
    afficherMatrice(table, tailleRow, tailleCol);
}

char **saisirMatriceCharacter(int rows, int cols) {
    char **table = (malloc(rows*sizeof(char*)));
    
    for(int i = 0; i < rows; i++) {
        table[i] = (malloc(cols*sizeof(char*)));
        for(int j = 0; j < rows; j++){
            printf("Table[%d][%d] : ", i, j);
            scanf("%s",&table[i][j]);
        }
        
    }
    
    return table;
}

void afficherMatriceCharacter(char **table, int row, int col) {
    printf("Afficher : \n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++) {
            printf("Table[%d][%d] : %s\n", i, j, &table[i][j]);
        }
    }
}

void exercice3() {
    // 3- Saisir une matrice des caractères avant de l’afficher.
    printf("3- Saisir un matrice des caracter\n");
    
    int tailleCol, tailleRow;
    
    printf("Nombre de Lignes : ");
    scanf("%d", &tailleRow);
    
    printf("Nombre de Columns : ");
    scanf("%d", &tailleCol);
    
    char **table = saisirMatriceCharacter(tailleRow, tailleCol);
    afficherMatriceCharacter(table, tailleRow, tailleCol);
    
}

char **remplirMatriceAPartirFichier(char **table, int *row, int *col) {

    
    FILE* fichier = NULL;
    
    int nrow, ncol;
    fichier = fopen("matrice.txt", "r");
    
    printf("Saisir une matrice des caractères a partir d'un fichier : \n");
    if(fichier != NULL) {
        for(int n= 0; n < 2; n++) {
            if(n == 0) {
                nrow = (int)fgetc(fichier) - 48;
            }
            else if(n == 1) {
                ncol = (int)fgetc(fichier) - 48;
            }
        }

        table = malloc((nrow)*sizeof(char*));

        for(int i = 0; i < nrow; i++) {
            table[i] = malloc((ncol)*sizeof(char));
            for(int j = 0; j < ncol; j++) {
                table[i][j] = (char)fgetc(fichier);
            }

        }
        *row = nrow;
        *col = ncol;
        printf("t");
        fclose(fichier);
    }

    return table;
}

void exercice4() {
    // 4- Saisir une matrice des caractères à partir d’un fichier avant de l’afficher

    char **table = NULL;
    int row = 0;
    int col = 0;

    int *pRow = &row;
    int *pCol = &col;

    table = remplirMatriceAPartirFichier(table, pRow, pCol);

    afficherMatriceCharacter(table, row, col);
    
}

int main() {
    // Saisir un tableau des entier (dynamique) avant de l’afficher.


    return 0;
}