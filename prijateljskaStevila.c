#include <stdio.h>
#include <math.h>

int vsotaDeliteljev(int kandidat) {
	int vsota = 1;

	for (int i = 2; i < ceil(sqrt(kandidat)); i++) {
		if (kandidat % i == 0) {
			vsota += i;
			vsota += (kandidat / i);
		}
	}

	return vsota;
}

int main() {
	int n = 0;
	scanf("%d", &n);

	int prijatelj = vsotaDeliteljev(n);
	
	if (vsotaDeliteljev(prijatelj) == n) {
		printf("%d\n", prijatelj);
	} else {
		printf("NIMA\n");
	}

	return 0;
}