#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


main() {
    int n;
    printf("\nSo phan tu cua day n = "); scanf("%d", &n);
    float s = 0.0;
    for (int i = 1; i <= n; ++i) {
        s += 1 / i;
    }
    printf("S = %0.2f", s);
    getch();
}