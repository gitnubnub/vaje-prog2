
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02, 03: h = 1
 * 04, 05, 06: preverjajo samo vsoto
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

Vozlisce* diagonala(Vozlisce* start, int* vsota) {
    int sum = 0;
    int h = 0;
    int w = 0;
    Vozlisce* trenutno = start;

    while (trenutno != NULL) {
        w++;
        trenutno = trenutno -> desno;
    }

    trenutno = start;
    while (trenutno != NULL) {
        h++;
        trenutno = trenutno -> dol;
    }

    int dolzina = (h > w ? w : h);
    Vozlisce* prejsnje = NULL;
    Vozlisce* zacetek = NULL;
    for (int i = 0; i < dolzina; i++) {
        trenutno = start;

        for (int j = 1; j < w - i; j++) {
            trenutno = trenutno -> desno;
        }

        for (int j = 0; j < i; j++) {
            trenutno = trenutno -> dol;
        }

        Vozlisce* novo = (Vozlisce*) calloc(1, sizeof(Vozlisce));
        if (prejsnje == NULL) {
            zacetek = novo;
        } else {
            prejsnje -> desno = novo;
        }

        sum += trenutno -> vsebina;
        novo -> vsebina = trenutno -> vsebina;
        novo -> desno = NULL;
        novo -> dol = NULL;

        prejsnje = novo;
    }

    *vsota = sum;
    return zacetek;
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo <diagonala> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga3.c).
    return 0;
}

#endif
