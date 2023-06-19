#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    int primer = 0;
    scanf("%d", &primer);
    int enaka = 1;

    for (int i = 1; i < n; i++) {
        int novo = 0;
        scanf("%d", &novo);
        if (novo != primer) {
            enaka = 0;
            break;
        }
    }

    printf("%d\n", enaka);
    return 0;
}