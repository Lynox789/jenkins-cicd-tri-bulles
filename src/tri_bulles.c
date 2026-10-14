#include "tri_bulles.h"

void tri_bulles(int tableau[], int taille) {
    for (int i = 0; i < taille - 1; i++)
        for (int j = 0; j < taille - i - 1; j++)
            if (tableau[j] > tableau[j + 1]) {
                int tmp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = tmp;
            }
}

int est_trie(const int tableau[], int taille) {
    for (int i = 0; i < taille - 1; i++)
        if (tableau[i] > tableau[i + 1])
            return 0;
    return 1;
}
