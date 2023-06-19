#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);

	int poskus = (a + b) / 2;
	int odgovor = 0;
	scanf("%d", &odgovor);
	while (odgovor != 0) {
		if (odgovor == 1) {
			a = poskus + 1;
		} else if (odgovor == -1) {
			b = poskus - 1;
		}
		poskus = (a + b) / 2;
		scanf("%d", &odgovor);
	}

	if (a == b) {
		printf("%d\n", a);
	} else if (a > b) {
		printf("PROTISLOVJE\n");
	} else {
		printf("%d %d\n", a, b);
	}

	return 0;
}