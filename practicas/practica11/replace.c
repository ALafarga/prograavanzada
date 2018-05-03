#include <stdio.h>
#include <string.h>

int main()
{
    char *fileName = "myfile.txt"; //si no le paso nada de path lo busca en el folder actual
    char *search = "open";
    char *replace = "abierto";
    int character;
    long streamPos = 0;
    int i = 0;
    FILE *myFile = fopen(fileName, "r");
    while (1)
    {
        character = fgetc(myFile);
        streamPos = ftell(myFile);
        if (feof(myFile))
        {
            break;
        }
        if(character == search[0]){
            i = 0;
            while(!feof(myFile) && search[i] == character){
                character = fgetc(myFile);
                i++;
            }
            if(feof(myFile)){
                break;
            }
            if( i == strlen(search)){
                printf("MATCH \n");
            } else {
                //rewind
                fseek(myFile, streamPos, SEEK_SET);
            }
        }
        // fputc(character, stdout);
        fputc(character, stdout);
        // fprintf(stderr, "character = %c\n", character);
        // PRINTDEBUG("character = %c\n", character);
    }
    fclose(myFile);
    return 0;
}