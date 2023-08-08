
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int nacini(int n, int m, int* porabljene) {
    int stevec = 0;

    for (int i = (n > m ? m : n) - 1; i > 0; i--) {
        if (!porabljene[i]) {
            for (int j = i - 1; j > 0; j--) {
                if (!porabljene[j] && i + j <= m) {
                    if (i + j == n) {
                        stevec++;
                    }
                    
                    if (n % (i + j) == 0) {
                        porabljene[i] = 1;
                        porabljene[j] = 1;
                        stevec += nacini(n / (i + j), m, porabljene);

                        porabljene[i] = 0;
                        porabljene[j] = 0;
                    }
                }
            }
        }
    }

    return stevec;
}

int main() {
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);

    int* porabljene = (int*) calloc(m, sizeof(int));

    int stNacinov = nacini(n, m, porabljene);
    printf("%d\n", stNacinov);

    return 0;
}
