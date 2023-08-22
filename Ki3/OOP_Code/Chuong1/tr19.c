#include <stdio.h>
//! #include <alloc.h> - alloc.h không phải thư viện chuẩn của C/C++ mà là của Turbo C/C++ => không hỗ trợ ở VS code => lỗi
//! để sử dụng hàm malloc thì sử dụng malloc trong stdlib.h
//* alloc.h
//* It's a header file that declares memory-management functions like malloc, free, realloc.
//* That header file is deprecated.


#include <stdlib.h> 
#include <conio.h>

int main() {
    int n; 
    printf("\nSo phan tu cua day n = "); scanf("%d", &n);
    float *x = (float*)malloc((n + 1) * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        printf("\n X[%d] = ", i);
        scanf("%f", x + i);
    }
    float tg;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1 ; j < n ; j++)
            if (x[i] > x[j]) // *(x + i) + *(x + j)
            {
                tg = x[i];
                x[i] = x[j];
                x[j] = tg;
            }
    printf("\n Day sau sap xep: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%0.2f ", x[i]); //*(x + i)
    }
    free(x);
    getch();
    
}