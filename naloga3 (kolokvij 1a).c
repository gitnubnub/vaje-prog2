
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int nacini(int n, int m) {
    int stevec = 0;

    for (int i = m; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i * j == n) {
                stevec++;
            } else {
                stevec += nacini(n - i * j, m);
            }
        }
    }

    return stevec;
}

int main() {
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);

    int stNacinov = nacini(n, m);
    printf("%d\n", stNacinov);
    return 0;
}
