#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    int najvecje = 0;
    int drugoNajvecje = 0;
    for (int i = 1; i <= n; i++) {
        int novo = 0;
        scanf("%d", &novo);

        if (novo >= najvecje) {
            drugoNajvecje = najvecje;
            najvecje = novo;
        } else if (novo >= drugoNajvecje) {
            drugoNajvecje = novo;
        }
    }

    printf("%d\n", drugoNajvecje);
    return 0;
}