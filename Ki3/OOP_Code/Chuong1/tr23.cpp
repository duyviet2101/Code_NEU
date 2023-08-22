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
        s += float(1) / float(i); //! ep theo kieu c++
        //* s += (float)1 / (float)(i) -  theo kieu c
    }
    printf("S = %0.2f", s);
    getch();
}