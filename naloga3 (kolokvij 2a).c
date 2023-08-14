
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02--06: y = 0, koordinate x nara"s"cajo
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

long kvRazdalja(int** koordinate, int i1, int i2) {
    long x1 = koordinate[0][i1];
    long y1 = koordinate[1][i1];
    long x2 = koordinate[0][i2];
    long y2 = koordinate[1][i2];
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

void moznePoti(int n, long k, int** koordinate, int* pot, int indeks, int poteza) {
    if (indeks == n - 1) {
        for (int i = 0; i < poteza - 1; i++) {
            if (i == 0 || pot[i] != 0) {
                printf("%d->", pot[i]);
            }
        }

        printf("%d\n", n - 1);
        return;
    }

    long doCilja2 = kvRazdalja(koordinate, indeks, n - 1);
    for (int i = 1; i < n; i++) {
        long doKamna2 = kvRazdalja(koordinate, indeks, i);
        long novaCilj2 = kvRazdalja(koordinate, i, n - 1);
        if (k >= doKamna2 && novaCilj2 < doCilja2) {
            pot[poteza] = i;
            moznePoti(n, k, koordinate, pot, i, poteza + 1);
            pot[poteza] = 0;
        }
    }

    return;
}

int main() {
    int n = 0;
    int K = 0;
    scanf("%d%d", &n, &K);

    int** koordinate = (int**) calloc(2, sizeof(int*));
    koordinate[0] = (int*) calloc(n, sizeof(int));
    koordinate[1] = (int*) calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        int x = 0;
        int y = 0;
        scanf("%d%d", &x, &y);
        koordinate[0][i] = x;
        koordinate[1][i] = y;
    }

    int* pot = (int*) calloc(n, sizeof(int));
    pot[0] = 0;
    long k = (long) K * (long) K;
    moznePoti(n, k, koordinate, pot, 0, 1);
    
    free(koordinate[0]);
    free(koordinate[1]);
    free(koordinate);
    free(pot);
    return 0;
}
