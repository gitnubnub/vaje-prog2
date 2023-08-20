
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02--06: graf je acikli"cen
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void moznePoti(int n, int k, int** utezi, int* ze, int* pot, int trenutni, int poteza) {
    if (k < 0) {
        return;
    }

    if (trenutni == n - 1) {
        for (int i = 0; i <  poteza - 1; i++) {
            printf("%d->", pot[i]);
        }

        printf("%d\n", n - 1);
        return;
    }

    for (int i = 1; i < n; i++) {
        if (ze[i] != 1 && utezi[trenutni][i] != -1) {
            ze[i] = 1;
            pot[poteza] = i;
            moznePoti(n, k - utezi[trenutni][i], utezi, ze, pot, i, poteza + 1);
            ze[i] = 0;
            pot[poteza] = 0;
        }
    }

    return;
}

int main() {
    int n = 0;
    int m = 0;
    int K = 0;
    scanf("%d%d%d", &n, &m, &K);

    int** utezi = (int**) calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        utezi[i] = (int*) calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            utezi[i][j] = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        int izvor = 0;
        int cilj = 0;
        int utez = 0;
        scanf("%d%d%d", &izvor, &cilj, &utez);
        utezi[izvor][cilj] = utez;
    }

    int* ze = (int*) calloc(n, sizeof(int));
    int* pot = (int*) calloc(n, sizeof(int));
    ze[0] = 1;
    pot[0] = 0;
    moznePoti(n, K, utezi, ze, pot, 0, 1);

    for (int i = 0; i < n; i++) {
        free(utezi[i]);
    }
    free(utezi);

    free(pot);
    return 0;
}
