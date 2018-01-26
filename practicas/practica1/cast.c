#include <stdio.h>

int main() {
    //int a = 2147483647;
    int a = 2;
    int j = 0, k = 0, l = 0;
    int *p;    
    long d = (long)a * a; //los modificadores se aplican automaticamente a int entonces
    //podriamos escribir long ind d = a * a;
    float f = 4.67;
    int e = 4;
    int c = (int)f + e;

    p = &a;
    *p = 400;
    p++;
    *p = 5555;

    //printf("a = %d, d = %li, f = %f, e = %d, c = %d \n",&a,d,f,e);
    printf("a = %d, p = %p, j = %d, k = %d, l = %d \n",a,p,j,k,l); //%p es cambio a hexadecimal
    return 0;
}