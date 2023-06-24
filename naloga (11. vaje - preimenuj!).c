
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    int vsota = 0;
    if (zacetek == NULL) {
        return vsota;
    }

    Vozlisce* trenutno = zacetek;
    while (trenutno != NULL) {
        vsota += trenutno -> podatek;
        trenutno = trenutno -> naslednje;
    }

    return vsota;
}

int vsotaR(Vozlisce* zacetek) {
    if (zacetek == NULL) {
        return 0;
    }
    
    if (zacetek -> naslednje == NULL) {
        return zacetek -> podatek;
    }

    return zacetek -> podatek + vsotaR(zacetek -> naslednje);
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    if (zacetek == NULL) {
        Vozlisce* novo = (Vozlisce*) calloc(1, sizeof(Vozlisce));
        novo -> podatek = element;
        novo -> naslednje = NULL;
        return novo;
    }
    
    if (element <= zacetek -> podatek) {
        Vozlisce* novo = (Vozlisce*) calloc(1, sizeof(Vozlisce));
        novo -> podatek = element;
        novo -> naslednje = zacetek;
        return novo;
    } else {
        Vozlisce* predhodno = zacetek;
        Vozlisce* trenutno = zacetek -> naslednje;
        
        while (trenutno != NULL) {
            if (element <= trenutno -> podatek) {
                Vozlisce* novo = (Vozlisce*) calloc(1, sizeof(Vozlisce));
                novo -> podatek = element;
                novo -> naslednje = trenutno;
                predhodno -> naslednje = novo;
                return zacetek;
            }

            predhodno = trenutno;
            trenutno = trenutno -> naslednje;    
        }

        Vozlisce* novo = (Vozlisce*) calloc(1, sizeof(Vozlisce));
        novo -> podatek = element;
        novo -> naslednje = NULL;
        predhodno -> naslednje = novo;
        return zacetek;
    }
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    if (zacetek == NULL || element <= zacetek -> podatek) {
        Vozlisce* novo = (Vozlisce*) calloc(1, sizeof(Vozlisce));
        novo -> podatek = element;
        novo -> naslednje = zacetek;
        zacetek = novo;
        return zacetek;
    }

    zacetek -> naslednje = vstaviUrejenoR(zacetek -> naslednje, element);
    return zacetek;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
