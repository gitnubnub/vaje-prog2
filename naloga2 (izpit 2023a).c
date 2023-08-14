
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Testni primeri:
 * 02--06: a = 1, b = n
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void moznosti(int n, int a, int b, int* izpis, int indeks, int zadnji) {
    if (indeks > b || (indeks == b && n != 0)) {
        return;
    }

    if (n == 0 && indeks > a - 1) {
        for (int i = 0; i < indeks - 1; i++) {
            printf("%d+", izpis[i]);
        }

        printf("%d\n", izpis[indeks - 1]);
        return;
    }

    for (int i = zadnji; i <= n; i++) {
        izpis[indeks] = i;
        moznosti(n - i, a, b, izpis, indeks + 1, i);
        izpis[indeks] = 0;
    }

    return;
}

int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    scanf("%d%d%d", &n, &a, &b);

    int* izpis = (int*) calloc(b, sizeof(int));
    moznosti(n, a, b, izpis, 0, 1);
    
    return 0;
}
