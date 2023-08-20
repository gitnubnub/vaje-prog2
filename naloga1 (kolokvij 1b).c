
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

int main() {
    int n = 0;
    scanf("%d", &n);

    int* a = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int* b = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int kvRazdalje = 0;
    for (int i = 0; i < n; i++) {
        kvRazdalje += ((a[i] - b[i]) * (a[i] - b[i]));
    }

    printf("%d\n", kvRazdalje);

    free(a);
    free(b);
    return 0;
}
