#include <stdio.h>
#include "operations.h"

int main (){
    char operation[200];
    int operatior1, operatior2;
    printf("%s\n", "What is the operation?");
    scanf("%s", operation);
    scanf("%d %d", &operatior1, &operatior2);
    printf("result: %d", add(operatior1, operatior2));

    return 0;
}