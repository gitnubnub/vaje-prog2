
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    char znak = fgetc(input);
    while (znak != EOF) {
        int zaceli = 0;
        while (znak != '\n' && znak != EOF) {
            if (znak != ' ') {
                fputc(znak, output);
                zaceli = 1;
            } else if (znak == ' ' && zaceli) {
                fputc(znak, output);
            }

            znak = fgetc(input);
        }

        if (znak == '\n') {
            fputc(znak, output);
            znak = fgetc(input);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
