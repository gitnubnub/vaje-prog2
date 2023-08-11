#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	scanf("%d", &n);

	char** imena = (char**) calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) {
		imena[i] = (char*) calloc(100, sizeof(char));
		scanf("%s", imena[i]);
	}

	char* izhod = (char*) calloc(100, sizeof(char));
	scanf("%s", izhod);

	int* pojavitve = (int*) calloc(1000000001, sizeof(int));
	int min = 0;
	int max = 0;
	int prvo = 1;

	for (int i = 0; i < n; i++) {
		FILE* input = fopen(imena[i], "r");
		int stevilo = 0;
		while (fscanf(input, "%d", &stevilo) != EOF) {
			pojavitve[stevilo]++;
			
			if (prvo) {
				min = stevilo;
				max = stevilo;
				prvo = 0;
			} else {
				if (stevilo < min) {
					min = stevilo;
				}

				if (stevilo > max) {
					max = stevilo;
				}
			}
		}

		fclose(input);
	}

	FILE* output = fopen(izhod, "w");
	for (int i = min; i <= max; i++) {
		if (pojavitve[i]) {
			for (int j = 1; j <= pojavitve[i]; j++) {
				fprintf(output, "%d\n", i);
			}
		}
	}

	fclose(output);
	for (int i = 0; i < n; i++) {
		free(imena[i]);
	}
	free(imena);

	free(izhod);
	free(pojavitve);
	return 0;
}