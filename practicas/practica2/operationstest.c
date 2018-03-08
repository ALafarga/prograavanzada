#include <stdio.h>
#include "operations.h"

void printTestMessage(int, char *, char *b);

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

    // if( result == expected )
    // {
    //     printf("%s\n" , "Addition test passed");
    // }
    // else
    // {
    //     printf("%s\n" , "Addition test failed");
    // }
    printTestMessage(result == expected, 
    "Adition test passed", 
    "Addition test failed");

//Test Substraction
    int d = 2147483644;
    int f = 2;

    int resultSubstaction = substraction(d,f);
    int expectedSubstraction = d - f;

    // if( resultSubstaction == expectedSubstraction )
    // {
    //     printf("%s\n" , "Substaction test passed");
    // }
    // else
    // {
    //     printf("%s\n" , "Substaction test failed");
    // }
    printTestMessage(resultSubstaction == expectedSubstraction,
                    "Substraction test passed",
                    "Substraction test failed");

    return 0;
}

void printTestMessage(int testResult, 
                    char *passedMessage, 
                    char *failedMessage)
{
    if( testResult )
    {
        printf("%s\n" , passedMessage);
    }
    else
    {
        printf("%s\n" , failedMessage);
    }
}