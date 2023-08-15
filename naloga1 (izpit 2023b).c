
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

    int curr = fgetc(input);
    int prev = -1;
    while (curr != EOF) {
        if (curr != prev) {
            fputc(curr, output);
        }

        prev = curr;
        curr = fgetc(input);
    }

    fclose(input);
    fclose(output);
    return 0;
}
