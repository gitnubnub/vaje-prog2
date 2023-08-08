
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
 *
 * Javni testni primeri (po te"zavnosti):
 * -- 02, 03: dol"zina vsakega vhodnega niza je enaka ciljnaDolzina;
 * -- 04, 05, 06, 07: dol"zina vsakega vhodnega niza je enaka 1;
 * -- 01, 08, 09, 10: splo"sni primeri.
 *
 * Javni testni primeri (po na"cinu priprave):
 * -- 01: primer iz besedila;
 * -- 01, 02, 04: ro"cno ustvarjeni;
 * -- ostali: samodejno generirani.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

//=============================================================================

char** naSredino(char** nizi, int ciljnaDolzina) {
    int velikost = 0;
    for (int i = 0; nizi[i] != NULL; i++) {
        velikost++;
    }

    char** nova = (char**) calloc(velikost + 1, sizeof(char*));
    for (int i = 0; i < velikost; i++) {
        nova[i] = (char*) calloc(ciljnaDolzina + 1, sizeof(char));
        for (int j = 0; j < ciljnaDolzina; j++) {
            nova[i][j] = '.';
        }
    }
    nova[velikost] = NULL;

    for (int i = 0; i < velikost; i++) {
        int dolzina = strlen(nizi[i]);
        int stPik = ciljnaDolzina - dolzina;
        int zacIndeks = stPik / 2;
        for (int j = 0; j < dolzina; j++) {
            nova[i][zacIndeks + j] = nizi[i][j];
        }
        nova[i][ciljnaDolzina] = '\0';
    }

    return nova;
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo naSredino testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    return 0;
}

#endif
