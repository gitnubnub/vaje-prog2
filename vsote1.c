#include <stdio.h>

int nacini(int vsota, int maxSumand) {
	if (vsota == 0) {
		return 1;
	}

	if (maxSumand == 0) {
		return 0;
	}

	int naslednjiSumand = maxSumand - 1;
	int razlika = vsota - maxSumand;
	if (maxSumand > razlika) {
		maxSumand = razlika;
	}

	int vsiNacini = nacini(razlika, maxSumand) + nacini(vsota, naslednjiSumand);
	return vsiNacini;
}

int main() {
	int n = 0;
	int k = 0;
	scanf("%d%d", &n, &k);

	int stNacinov = nacini(n, k);
	printf("%d\n", stNacinov);

	return 0;
}