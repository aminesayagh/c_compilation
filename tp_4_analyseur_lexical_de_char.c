#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Cette fonction demande à l'utilisateur de saisir une matrice de char de taille row x col
// et renvoie cette matrice sous forme de tableau à deux dimensions
char **saisirMatrice(int row, int col) {
    char **matrice;
    matrice = (char**)malloc(row*sizeof(char*));

    // Alloue de la mémoire pour chaque ligne de la matrice
    for (int i = 0; i < row; i++) {
        matrice[i] = (char*)malloc(col*sizeof(char));

        // Demande à l'utilisateur de saisir chaque élément de la matrice
        for (int j = 0; j < col; j++) {
            printf("matrice[%d][%d] = ", i, j);
            scanf(" %c", &matrice[i][j]);
        }
    }
    return matrice;
}

// Cette fonction affiche la matrice passée en paramètre
void afficherMatrice(char **matrice, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("matrice[%d][%d] = %c \n", i, j, matrice[i][j]);
        }
    }
}

// Cette fonction demande à l'utilisateur de saisir un tableau de char de taille row
// et renvoie ce tableau
char *saisirTableau(int row) {
    char *tab = (char*)malloc(row*sizeof(char));
    for (int i = 0; i < row; i++) {
        printf("Tab[%d] = ", i);
        scanf(" %c", &tab[i]);
    }
    return tab;
}

// Cette fonction calcule la trace du mot passé en paramètre dans la matrice de transition
// Elle renvoie -1 si le mot n'est pas reconnu par le langage, sinon elle renvoie l'état final
int trace(char **matriceTransition, int *mot, int taille) {
    int trace = 0;
    for (int i = 0; i < taille && trace != -1; i++) {
        trace = matriceTransition[trace][mot[i]];
        printf("T[%d][%d] = %d\n", trace, mot[i], trace);
        if(trace == -1) return -1;
    }
    return trace;
}

int* convertirMotCharVersInt(char *mot, int taille) {
    int *motConverti = (int *)malloc(sizeof(int)* taille);
    for(int i= 0; i < taille; i++){
        switch(mot[i]) {
            case 'a':
                motConverti[i] = 0;
                break;
            case 'b':
                motConverti[i] = 1;
                break;
            case 'c':
                motConverti[i] = 2;
                break;
            default:
                motConverti[i] = -1;
                break;
        }
    }
    return motConverti;
}

int main() {
    // Demande à l'utilisateur de saisir les dimensions de la matrice de transition
    int row = 0, col = 0;
    printf("Nombre lignes : ");
    scanf("%d", &row);
    printf("Nombre colonnes : ");
    scanf("%d", &col);

    // Demande à l'utilisateur de saisir la matrice de transition
    char **matrice = saisirMatrice(row, col);
    afficherMatrice(matrice, row, col);

    // Demande à l'utilisateur de saisir le mot à tester
    char *mot = NULL;
    int tailleMot = 0;
    printf("Taille du mot : ");
    scanf("%d", &tailleMot);
    mot = saisirTableau(tailleMot);
    int motReels = convertirMotCharVersInt(mot);

    // Calcule la trace du mot dans la matrice de transition
    int traceDuMot = trace(matrice, motReels, tailleMot);

    // Affiche si le mot est reconnu ou non par le langage
    if (traceDuMot == -1) {
        printf("Le mot n'est pas reconnu par le langage");
    } else {
        printf("Le mot est reconnu par le langage");
    }

    return 0;
}