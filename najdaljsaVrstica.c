#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	FILE* inp = fopen(argv[1], "r");

	int maxLen = 0;
	char maxNiz[1000000];
	char niz[1000000];
	while (fgets(niz, 1000000, inp) != NULL) {
		int res = strlen(niz);
		if  (res > maxLen) {
			maxLen = res;
			strcpy(maxNiz, niz);
		}
	}

	FILE* out = fopen(argv[2], "w");
	fputs(maxNiz, out);

	fclose(inp);
	fclose(out);
	return 0;
}