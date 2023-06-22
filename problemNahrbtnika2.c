#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int*** memo; // Memoization table

int optimalno(int* prostornine, int* cene, int v, int n, int k) {
    if (v == 0 || n == 0) {
        return 0;
    }

    if (memo[n][v][k] != -1) {
        return memo[n][v][k];
    }

    if (prostornine[n - 1] <= v) {
        if (prostornine[n - 1] % 2) {
			if (k > 0) {
	            memo[n][v][k] = max(cene[n - 1] + optimalno(prostornine, cene, v - prostornine[n - 1], n - 1, k - 1), optimalno(prostornine, cene, v, n - 1, k));
			} else {
				memo[n][v][k] = optimalno(prostornine, cene, v, n - 1, k);
			}
		} else {
			memo[n][v][k] = max(cene[n - 1] + optimalno(prostornine, cene, v - prostornine[n - 1], n - 1, k), optimalno(prostornine, cene, v, n - 1, k));
		}
	} else {
		memo[n][v][k] = optimalno(prostornine, cene, v, n - 1, k);
	}

    return memo[n][v][k];
}

int main() {
    int v = 0;
    int n = 0;
    int k = 0;
    scanf("%d%d%d", &v, &n, &k);

    int vseProstornine = 0;
    int oddCount = 0;
    int* prostornine = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        int p = 0;
        scanf("%d", &p);
        prostornine[i] = p;
        vseProstornine += p;
        if (p % 2) {
            oddCount++;
        }
    }

    int vseCene = 0;
    int* cene = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        int c = 0;
        scanf("%d", &c);
        cene[i] = c;
        vseCene += c;
    }

    if (vseProstornine <= v && oddCount <= k) {
        printf("%d\n", vseCene);
        return 0;
    } else {
        memo = (int***) malloc((n + 1) * sizeof(int**));
        for (int i = 0; i <= n; i++) {
            memo[i] = (int**) malloc((v + 1) * sizeof(int*));
            for (int j = 0; j <= v; j++) {
                memo[i][j] = (int*) calloc(k + 1, sizeof(int));
                for (int l = 0; l <= k; l++) {
                    memo[i][j][l] = -1;
                }
            }
        }

        int maxCena = optimalno(prostornine, cene, v, n, k);
        printf("%d\n", maxCena);

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= v; j++) {
                free(memo[i][j]);
            }
            free(memo[i]);
        }
        free(memo);

        return 0;
    }
}