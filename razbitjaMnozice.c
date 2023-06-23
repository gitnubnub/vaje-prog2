//3. in 10. testni primer je vrglo sysmalloc: Assertion failed

#include <stdio.h>
#include <stdlib.h>

void podzaporedja(long polVsota, int indeks, int* t, int* izbrani, int n, long currSum) {
    if (indeks - 1 == n || currSum > polVsota) {
		return;
	}

    if (currSum == polVsota) {
        printf("{%d", t[0]);
        for (int i = 1; i < indeks; i++) {
            if (izbrani[i]) {
				printf(", %d", t[i]);
			}
        }
        printf("}\n");
        return;
    }

    izbrani[indeks] = 1;
    podzaporedja(polVsota, indeks + 1, t, izbrani, n, currSum + t[indeks]);
    izbrani[indeks] = 0;
    podzaporedja(polVsota, indeks + 1, t, izbrani, n, currSum);
    
    return;
}

int main() {
    int n = 0;

    scanf("%d", &n);

    int* t = (int*) calloc(n, sizeof(int));
    int* izbrani = (int*) calloc(n, sizeof(int));

    long vsota = 0;
	for (int i = 0; i < n; i++) {
        int st = 0;
		scanf("%d", &st);
		t[i] = st;
        vsota += st;
    }

    izbrani[0] = 1;
    podzaporedja(vsota / 2, 1, t, izbrani, n, t[0]);
	free(t);
	free(izbrani);

    return 0;
}