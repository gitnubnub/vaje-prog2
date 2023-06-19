#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);
    
    int vsota = a + b;
    int modulo = vsota % 10;
    printf("%d\n", modulo);

    return 0;
}