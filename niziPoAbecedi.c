#include <stdio.h>
#include <stdlib.h>

void nizi(int i, int n, char* t, char c1, char c2) {
    if (i == n || t[i - 1] == ' ') {
        for (int k = 0; k < n; k++) {
            if (t[k] == ' ') {
				break;
			}
            printf("%c", t[k]);
        }
        printf("\n");
        return;
    }

    for (char j = c1 - 1; j <= c2; j++) {
        if (i == 0 && j == c1 - 1) {
        	continue;
		}

        if (j == c1 - 1) {
            t[i] = ' ';
            nizi(i + 1, n, t, c1, c2);
        } else {
            t[i] = j;
            nizi(i + 1, n, t, c1, c2);
        }
    }

    return;
}

int main() {
    int n = 0;
    char c1;
    char c2;

    scanf("%d %c %c", &n, &c1, &c2);

    char* t = (char*) calloc(n, sizeof(char));

    nizi(0, n, t, c1, c2);

    return 0;
}