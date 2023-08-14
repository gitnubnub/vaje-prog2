
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga2.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

// po potrebi dopolnite ...

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** noviA, Vozlisce** noviB) {
    int** podatki = (int**) calloc(2, sizeof(int*));
    
    podatki[0] = (int*) calloc(10000, sizeof(int));
    Vozlisce* trenutno = a;
    while (trenutno != NULL) {
        int stevilo = trenutno -> podatek;
        podatki[0][stevilo] = 1;
        trenutno = trenutno -> naslednje;
    }

    podatki[1] = (int*) calloc(10000, sizeof(int));
    trenutno = b;
    while (trenutno != NULL) {
        int stevilo = trenutno -> podatek;
        podatki[1][stevilo] = 1;
        trenutno = trenutno -> naslednje;
    }

    trenutno = a;
    Vozlisce* prejsnje = a;
    while (trenutno != NULL) {
        int stevilo = trenutno -> podatek;
        if (podatki[1][stevilo] == 1) {
            if (trenutno == a) {
                a = a -> naslednje;
                trenutno = a;
                prejsnje = a;
            } else if (trenutno -> naslednje == NULL) {
                prejsnje -> naslednje = NULL;
                trenutno = NULL;
            } else {
                prejsnje -> naslednje = trenutno -> naslednje;
                trenutno = prejsnje -> naslednje;
            }
        } else {
            prejsnje = trenutno;
            trenutno = trenutno -> naslednje;
        }
    }
    *noviA = a;

    trenutno = b;
    prejsnje = b;
    while (trenutno != NULL) {
        int stevilo = trenutno -> podatek;
        if (podatki[0][stevilo] == 1) {
            if (trenutno == b) {
                b = b -> naslednje;
                trenutno = b;
                prejsnje = b;
            } else if (trenutno -> naslednje == NULL) {
                prejsnje -> naslednje = NULL;
                trenutno = NULL;
            } else {
                prejsnje -> naslednje = trenutno -> naslednje;
                trenutno = prejsnje -> naslednje;
            }
        } else {
            prejsnje = trenutno;
            trenutno = trenutno -> naslednje;
        }
    }
    *noviB = b;

    free(podatki[0]);
    free(podatki[1]);
    free(podatki);
    return;
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo izlociSkupne testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    return 0;
}

#endif
