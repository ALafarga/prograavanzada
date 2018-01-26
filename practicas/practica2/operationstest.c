#include <stdio.h>
#include "operations.h"

int main() {
    //Test addition
    //priemra prueba
    //    int a = 2147483647;
    //      int b = 2147483647;
    //segunda prueba
    int a = 2147483644;
    int b = 2;

    int result = add(a,b);
    int expected = a + b;

    if( result == expected )
    {
        printf("%s\n" , "Addition test passed");
    }
    else
    {
        printf("%s\n" , "Addition test failed");
    }

    return 0;
}