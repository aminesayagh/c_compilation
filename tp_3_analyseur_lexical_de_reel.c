#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Cette fonction demande à l'utilisateur de saisir une matrice de taille row x col
// et renvoie cette matrice sous forme de tableau à deux dimensions
int **saisirMatrice(int row, int col) {
    int **matrice;
    matrice = (int**)malloc(row*sizeof(int*));

    // Alloue de la mémoire pour chaque ligne de la matrice
    for (int i = 0; i < row; i++) {
        matrice[i] = (int*)malloc(col*sizeof(int));

        // Demande à l'utilisateur de saisir chaque élément de la matrice
        for (int j = 0; j < col; j++) {
            printf("matrice[%d][%d] = ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
    return matrice;
}

// Cette fonction affiche la matrice passée en paramètre
void afficherMatrice(int **matrice, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("matrice[%d][%d] = %d \n", i, j, matrice[i][j]);
        }
    }
}

// Cette fonction demande à l'utilisateur de saisir un tableau de taille row
// et renvoie ce tableau
int *saisirTableau(int row) {
    int *tab = (int*)malloc(row*sizeof(int));
    for (int i = 0; i < row; i++) {
        printf("Tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    return tab;
}

// Cette fonction calcule la trace du mot passé en paramètre dans la matrice de transition
// Elle renvoie -1 si le mot n'est pas reconnu par le langage, sinon elle renvoie l'état final
int trace(int **matriceTransition, int *mot, int taille) {
    int trace = 0;
    for (int i = 0; i < taille && trace != -1; i++) {
        trace = matriceTransition[trace][mot[i]];
        printf("T[%d][%d] = %d\n", trace, mot[i], trace);
    }
    return trace;
}


int main() {
    // Demande à l'utilisateur de saisir les dimensions de la matrice de transition
    int row = 0, col = 0;
    printf("Nombre lignes : ");
    scanf("%d", &row);
    printf("Nombre colonnes : ");
    scanf("%d", &col);

    // Demande à l'utilisateur de saisir la matrice de transition
    int **matrice = saisirMatrice(row, col);
    afficherMatrice(matrice, row, col);

    // Demande à l'utilisateur de saisir le mot à tester
    int *mot = NULL;
    int tailleMot = 0;
    printf("Taille du mot : ");
    scanf("%d", &tailleMot);
    mot = saisirTableau(tailleMot);

    // Calcule la trace du mot dans la matrice de transition
    int traceDuMot = trace(matrice, mot, tailleMot);
    
    int etatFinal;
    printf("Definiser l'etat final de l'automate");
    scanf("%d", &etatFinal);

    // Affiche si le mot est reconnu ou non par le langage
    if (traceDuMot == -1) {
        printf("Le mot n'est pas reconnu par le langage");
    } else {
        printf("Le mot est reconnu par le langage");
        // La reconnessance du trace comme etat finale
        if(etatFinal == traceDuMot) {
            printf("Le trace et un etat final");
        }
    }

    return 0;
}