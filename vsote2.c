#include <stdio.h>
#include <stdlib.h>

void nacini(int n, int k, int* p, int j) {
    if (n < k) {
        k = n;
    }

    if (k == 0) {
        if (n > 0) {
            return;
        }

        for (int i = 0; i < j; i++) {
            if (i > 0) {
                printf(" + ");
            }
            printf("%d", p[i]);
        }
        printf("\n");
        return;
    }

    p[j] = k;
    nacini(n - k, k, p, j + 1);
    p[j] = 0;
    nacini(n, k - 1, p, j);

    return;
}

int main() {
    int n = 0;
    int k = 0;

    scanf("%d%d", &n, &k);

    int* p = (int*) calloc(n, sizeof(int));

    nacini(n, k, p, 0);
    return 0;
}
