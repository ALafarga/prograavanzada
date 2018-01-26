#include <stdio.h>

int main (){
    int a[5] = {1,2,3,4,5};
    int *pa;
    pa = a;
    *pa =27;
    pa[2] = 45;
    *(pa + 3) = 200; //la groseria, estoye scribiendo en a[3]
    //pa = 27; //quien sabe a donde apunta
    //for(int i = 0; i < 5; i++) {
    for(int i = 0; i < sizeof(a)/sizeof(int); i++) {
        // int * es el tipo de dato apuntador
        printf("a[%d] = %d ", i,a[i]);
    }
    printf("\n");
    return 0;
}