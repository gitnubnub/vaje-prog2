#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	scanf("%d\n", &n);
	int* tabela = (int*) calloc(n, sizeof(int));

	for (int i = 1; i <= n; i++) {
		int stevilo = 0;
		scanf("%d", &stevilo);

		if (stevilo >= n || stevilo < 0) {
			printf("NE\n");
			return 0;
		}

		tabela[stevilo]++;
		if (tabela[stevilo] > 1) {
			printf("NE\n");
			return 0;
		}
	}

	printf("DA\n");

	free(tabela);
	return 0;
}