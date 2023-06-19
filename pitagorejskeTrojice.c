#include <stdio.h>
#include <math.h>

int main() {
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);

	int stevec = 0;
	for (int c = m; c <= n; c++) {
		int kvadrat = c * c;
		for (int a = 1; a < c; a++) {
			int razlika = kvadrat - a * a;
			int b = round(sqrt(razlika));
			if (b * b == razlika) {
				stevec++;
				break;
			}
		}
	}

	printf("%d\n", stevec);
	return 0;
}