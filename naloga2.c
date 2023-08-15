
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

void moznosti(char* niz, int a, int b, int dolzina, char** izpis, int crka, int podniz) {
    if (crka == dolzina) {
        if (podniz >= a && podniz <= b) {
            for (int i = 0; i < podniz; i++) {
                for (int j = 0; izpis[i][j] != -1; j++) {
                    putchar(izpis[i][j]);
                }

                if (i != podniz - 1) {
                    printf("|");
                } else {
                    printf("\n");
                    return;
                }
            }
        } else {
            return;
        }
    }

    if (podniz >= b) {
        return;
    }

    int dolPod = dolzina - crka;
    for (int i = 0; i <= dolPod; i++) {
        izpis[podniz][i] = niz[crka];
        izpis[podniz][i + 1] = -1;
        moznosti(niz, a, b, dolzina, izpis, crka + 1, podniz + 1);

        crka++;
        if (crka >= dolzina) {
            break;
        }
    }

    return;
}

int main() {
    char* niz = (char*) calloc(16, sizeof(char));
    int a = 0;
    int b = 0;
    scanf("%s%d%d", niz, &a, &b);

    int dolzina = strlen(niz);
    char** izpis = (char**) calloc(b, sizeof(char*));
    for (int i = 0; i < b; i++) {
        izpis[i] = (char*) calloc(15, sizeof(char));
        for (int j = 0; j < 15; j++) {
            izpis[i][j] = -1;
        }
    }
    moznosti(niz, a, b, dolzina, izpis, 0, 0);
    
    return 0;
}
