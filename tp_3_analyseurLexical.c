#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int **saisirMatrice(int row, int col){
    int **matrice;
    matrice = (int**)malloc(row*sizeof(int*));
    for(int i = 0; i < row; i++){
        matrice[i] = (int*)malloc(col*sizeof(int));
        for(int j = 0; j < col; j++) {
            printf("matrice[%d][%d] = ",i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
    return matrice;
}
void afficherMatrice(int **matrice, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("matrice[%d][%d] = %d \n",i, j, matrice[i][j]);
        }
    }
}

int *saisirTableau(int row) {
    int *tab = (int*)malloc(row*sizeof(int));
    for(int i = 0;i < row; i++){
        printf("Tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    return tab;
}

int trace(int **matriceTransition, int *mot, int taille){
    int trace = 0;
    for(int i = 0; i < taille && trace != -1; i++) {
        trace = matriceTransition[trace][mot[i]];
        printf("T[%d][%d] = %d\n" , trace, mot[i],trace);
    }
    return trace;
    
}

int main() {

    // definir la matrice
    int **matrice = NULL;

    int row = 0, col = 0;
    printf("Nombre ligne : ");
    scanf("%d", &row);
    printf("Nombre columns : ");
    scanf("%d", &col);

    matrice = saisirMatrice(row,col);
    afficherMatrice(matrice,row , col);

    // definir le mot
    int *mot = NULL;
    int tailleMot = 0;
    printf("definiser la taille du mot = ");
    scanf("%d", &tailleMot);
    mot = saisirTableau(tailleMot);

    int traceDuMot = trace(matrice, mot, tailleMot);
    if(traceDuMot == -1){
        printf("Le mot n'est pas reconnue par le langage");
    }else{
        printf("Le mot est reconnue par le langage");
    }
    
    return 0;
}