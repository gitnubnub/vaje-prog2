#include <stdio.h>
#include <limits.h>

int main() {
	int n = 0;
	scanf("%d", &n);

	int maxVsota = INT_MIN;
	int tekocaVsota = 0;
	for (int i = 1; i <= n; i++) {
		int stevilo = 0;
		scanf("%d", &stevilo);
		
		tekocaVsota += stevilo;
		if (tekocaVsota > maxVsota) {
			maxVsota = tekocaVsota;
		}

		if (tekocaVsota < 0) {
			tekocaVsota = 0;
		}
	}

	printf("%d\n", maxVsota);
	return 0;
}