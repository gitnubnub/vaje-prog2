#include <stdio.h>

long obrat(long stevilo) {
	long obrnjen = 0;

	while (stevilo > 0) {
		obrnjen *= 10;
		obrnjen += (stevilo % 10);
		stevilo /= 10;
	}

	return obrnjen;
}

int main() {
	int k = 0;
	int a = 0;
	int b = 0;
	scanf("%d%d%d", &k, &a, &b);

	int stevec = 0;
	for (int i = a; i <= b; i++) {
		long stevilo = i;
		stevilo += obrat(stevilo);

		for (int j = 2; j <= k; j++) {
			long obrnjen = obrat(stevilo);
			if ((stevilo >= 10 && stevilo == obrnjen) || stevilo > 100000000000000000) {
				break;
			} else {
				stevilo += obrnjen;
			}
		}

		if (stevilo != obrat(stevilo)) {
			stevec++;
		}
	}

	printf("%d\n", stevec);
	return 0;
}