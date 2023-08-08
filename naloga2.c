
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
 * -- 02, 03, 04: en sam vhodni niz;
 * -- 05, 06, 07: vsi vhodni nizi so enako dolgi;
 * -- 01, 08, 09, 10: splo"sni primeri.
 *
 * Javni testni primeri (po na"cinu priprave):
 * -- 01: primer iz besedila;
 * -- 01, 02, 05: ro"cno ustvarjeni;
 * -- ostali: samodejno generirani.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

//=============================================================================

char** poStolpcih(char** nizi, int stVhodnih, int* stIzhodnih) {
    int najdaljsi = 0;
    for (int i = 0; i < stVhodnih; i++) {
        int dolzina = 0;
        for (int j = 0; nizi[i][j] != '\0'; j++) {
            dolzina++;
        }

        if (dolzina > najdaljsi) {
            najdaljsi = dolzina;
        }
    }

    char** nova = (char**) calloc(najdaljsi, sizeof(char*));
    for (int i = 0; i < najdaljsi; i++) {
        nova[i] = (char*) calloc(stVhodnih + 1, sizeof(char));
        int stevec = 0;
        for (int j = 0; j < stVhodnih; j++) {
            if (strlen(nizi[j]) > i) {
                nova[i][stevec] = nizi[j][i];
                stevec++;
            }
        }
    }

    *stIzhodnih = najdaljsi;
    return nova;
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo poStolpcih testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    return 0;
}

#endif
