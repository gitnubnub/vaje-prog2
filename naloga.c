
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    int sum = 0;
    int* kazalec = zac;
    while (kazalec != kon) {
        sum += *kazalec;
        kazalec++;
    }
    sum += *kon;
    return sum;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    if (*indeks == -1) {
        *indeks = (*kazalec - t);
    } else {
        *kazalec = t + *indeks;
    }
}

void frekvenceCrk(char* niz, int** frekvence) {
    int* abeceda = (int*) calloc(26, sizeof(int));
    *frekvence = abeceda;

    for (int i = 0; niz[i] != '\0'; i++) {
        int crka = niz[i];
        if (crka >= 'A' && crka <= 'Z') {
            abeceda[crka - 'A']++;
        } else if (crka >= 'a' && crka <= 'z') {
            abeceda[crka - 'a']++;
        }
    }
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
