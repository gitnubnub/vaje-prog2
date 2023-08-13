
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    char* vhodniNiz = (char*) calloc(100000, sizeof(char));
    int dolzina = 0;
    char znak = fgetc(input);
    while (znak != EOF) {
        vhodniNiz[dolzina] = znak;
        dolzina++;
        znak = fgetc(input);
    }

    for (int i = 0; i < dolzina; i++) {
        if (i + 1 < dolzina && vhodniNiz[i] == '"' && (vhodniNiz[i + 1] == 'C' || 
        vhodniNiz[i + 1] == 'c' || vhodniNiz[i + 1] == 'S' || vhodniNiz[i + 1] == 's' || 
        vhodniNiz[i + 1] == 'Z' || vhodniNiz[i + 1] == 'z')) {
            fputc(vhodniNiz[i + 1], output);
            i++;
        } else {
            fputc(vhodniNiz[i], output);
        }
    }

    free(vhodniNiz);
    fclose(input);
    fclose(output);
    return 0;
}
