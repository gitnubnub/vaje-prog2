//dela 32 (kinda random) testnih primerov, ostali segementation fault
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    FILE* input = fopen(argv[1], "rb");
    FILE* output = fopen(argv[2], "wb");

    int* tabela = (int*) calloc(10001, sizeof(int));
    int dolzina = 0;
    int stevilo = fgetc(input);

    while (stevilo != EOF) {
        tabela[dolzina] = stevilo;
        dolzina++;
        stevilo = fgetc(input);
    }

    for (int i = 0; i < dolzina; i++) {
        if (i + 1 < dolzina && tabela[i] == 0x1B && tabela[i + 1] == 0xC9) {
            i++;
        }
        fputc(tabela[i], output);
    }

    fclose(input);
    fclose(output);
    free(tabela);
    return 0;
}
