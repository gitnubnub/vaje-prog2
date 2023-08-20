
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

int main() {
    int n = 0;
    scanf("%d", &n);

    int* tabela = (int*) calloc(n, sizeof(int));
    int vsota = 0;
    for (int i = 0; i < n; i++) {
        int stevilo = 0;
        scanf("%d", &stevilo);
        tabela[i] = stevilo;
        vsota += stevilo;
    }

    int palindrom = 1;
    for (int i = 0; i < n / 2; i++) {
        if (tabela[i] != tabela[n - 1 - i]) {
            palindrom = 0;
        }
    }

    if (palindrom) {
        printf("DA\n");
    } else {
        printf("NE\n");
    }
    printf("%d\n", vsota);

    return 0;
}
