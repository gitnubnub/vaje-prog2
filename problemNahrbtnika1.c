#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int** memo; // Memoization table

int optimalno(int* prostornine, int* cene, int v, int n) {
	if (v == 0 || n == 0) {
		return 0;
	}

	if (memo[n][v] != -1) {
		return memo[n][v];
	}

	if (prostornine[n - 1] > v) {
		memo[n][v] = optimalno(prostornine, cene, v, n - 1);
	} else {
		memo[n][v] = max(cene[n - 1] + optimalno(prostornine, cene, v - prostornine[n - 1], n - 1), optimalno(prostornine, cene, v, n - 1));
	}

	return memo[n][v];
}

int main() {
	int v = 0;
	int n = 0;
	scanf("%d%d", &v, &n);

	int vseProstornine = 0;
	int* prostornine = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		int p = 0;
		scanf("%d", &p);
		prostornine[i] = p;
		vseProstornine += p;
	}

	int vseCene = 0;
	int* cene = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		int c = 0;
		scanf("%d", &c);
		cene[i] = c;
		vseCene += c;
	}

	if (vseProstornine <= v) {
		printf("%d\n", vseCene);
	} else {
		memo = (int**) calloc(n + 1, sizeof(int*));
		for (int i = 0; i <= n; i++) {
			memo[i] = (int*) calloc(v + 1, sizeof(int));
			for (int j = 0; j <= v; j++) {
				memo[i][j] = -1;
			}
		}

		int maxCena = optimalno(prostornine, cene, v, n);
		printf("%d\n", maxCena);

		for (int i = 0; i <= n; i++) {
			free(memo[i]);
		}
		free(memo);
	}

	free(prostornine);
	free(cene);

	return 0;
}
