#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINTDEBUG(...) \
    do \
    { \
        char *debug; \
        debug = getenv("DEBUG"); \
        if (debug != NULL && !strcasecmp(debug, "y")) \
        { \
            fprintf(stderr, __VA_ARGS__); \
        } \
    } while (0)

int main(){
    //cualquier cosa que este en el input lo vamos a poner en la salida
    int character;
    while(1){
        character = fgetc(stdin);
        if(feof(stdin))
        {
            break;
        }

        // fputc(character, stdout);
        fputc(character, stdout);
        // fprintf(stderr, "character = %c\n", character);
        PRINTDEBUG("character = %c\n", character);
    }
    return 0;
}