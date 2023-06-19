
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    int stevec = 0;
    for (int i = 0; niz[i] != '\0'; i++) {
        if (niz[i] == znak) {
            stevec++;
        }
    }
    return stevec;
}

int dolzinaNiza(char* niz, char znak) {
    int stevec = 0;
    for (int i = 0; niz[i] != '\0' && niz[i] != znak; i++) {
        stevec++;
    }
    return stevec;
}

char* kopirajDoZnaka(char* niz, char znak) {
    char* novNiz = (char*) calloc(dolzinaNiza(niz, znak) + 1, sizeof(char));
    for (int i = 0; niz[i] != '\0' && niz[i] != znak; i++) {
        novNiz[i] = niz[i];
        novNiz[i + 1] = '\0';
    }
    return novNiz;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    char* zacetek = niz;
    int stLocil = steviloZnakov(niz, locilo);
    *stOdsekov = stLocil + 1;
    char** zacetkiKopij = (char**) calloc(*stOdsekov, sizeof(char*));
    for (int i = 0; i <= stLocil; i++) {
        zacetkiKopij[i] = kopirajDoZnaka(zacetek, locilo);
        int length = dolzinaNiza(zacetek, locilo);
        zacetek += (length + 1);
    }

    return zacetkiKopij;
}

#ifndef test

int main() {
    /*printf("pesem, e: %d\n", steviloZnakov("pesem", 'e'));
    printf("banana, a: %d\n", steviloZnakov("banana", 'a'));
    printf("mississippi, s: %d\n", steviloZnakov("mississippi", 's'));*/
    return 0;
}

#endif
