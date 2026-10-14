#include <stdio.h>
#include <stdlib.h>
#include "../src/tri_bulles.h"

static int echecs = 0;

#define VERIFIER(cond, nom)                                   \
    do {                                                      \
        if (cond) printf("[OK] %s\n", nom);                   \
        else { printf("[KO] %s\n", nom); echecs++; }          \
    } while (0)

int main(void) {
    int a[] = {5, 2, 9, 1, 5, 6};
    tri_bulles(a, 6);
    VERIFIER(est_trie(a, 6) && a[0] == 1 && a[5] == 9, "tableau quelconque");

    int deja[] = {1, 2, 3, 4};
    tri_bulles(deja, 4);
    VERIFIER(est_trie(deja, 4) && deja[0] == 1 && deja[3] == 4, "tableau deja trie");

    int inverse[] = {4, 3, 2, 1};
    tri_bulles(inverse, 4);
    VERIFIER(est_trie(inverse, 4) && inverse[0] == 1, "tableau trie a l'envers");

    int neg[] = {3, -1, 0, -7};
    tri_bulles(neg, 4);
    VERIFIER(neg[0] == -7 && neg[3] == 3, "valeurs negatives");

    int un[] = {42};
    tri_bulles(un, 1);
    VERIFIER(un[0] == 42, "un seul element");

    tri_bulles(NULL, 0);
    VERIFIER(1, "tableau vide (taille 0)");

    int grand[1000];
    srand(1);
    for (int i = 0; i < 1000; i++) grand[i] = rand();
    tri_bulles(grand, 1000);
    VERIFIER(est_trie(grand, 1000), "1000 valeurs aleatoires");

    if (echecs) {
        printf("%d test(s) en echec\n", echecs);
        return 1;      /* code non nul => le build Jenkins passe en rouge */
    }
    printf("Tous les tests passent\n");
    return 0;
}
