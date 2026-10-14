#include <stdio.h>
#include <stdlib.h>
#include "tri_bulles.h"

int main(int argc, char **argv) {
    int taille = 5000;
    if (argc > 1) {
        taille = atoi(argv[1]);
        if (taille <= 0) {
            fprintf(stderr, "Usage : %s [taille > 0]\n", argv[0]);
            return 2;
        }
    }

    int *tableau = malloc((size_t)taille * sizeof(int));
    if (tableau == NULL) {
        perror("malloc");
        return 1;
    }

    srand(42);
    for (int i = 0; i < taille; i++)
        tableau[i] = rand() % 100000;

    tri_bulles(tableau, taille);

    printf("Tri de %d éléments : min = %d, max = %d, trié = %s\n",
           taille, tableau[0], tableau[taille - 1],
           est_trie(tableau, taille) ? "oui" : "non");

    int ok = est_trie(tableau, taille);
    free(tableau);
    return ok ? 0 : 1;
}
