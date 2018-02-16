#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct distancia 
{
    int id;
    double distancia;
};
int pointX;
int pointY;
int n = 0;
char * referencia;
int cuadradoX0[50];   //TODO: no se como hacerlos dinamicos asi que los hacemos al maximo que es 50 por el momento
int cuadradoY0[50];
int cuadradoXinv0[50];
int cuadradoYinv0[50];
int cuadradoX1[50];   
int cuadradoY1[50];
int cuadradoXinv1[50];
int cuadradoYinv1[50];

struct distancia distancias[50];

void 

double calcularDistancias();

void sortDistancias(struct distancia []);

void input ();

int cuadradoMasCercano ();

void getCuadrados ();

void presetCase()
{
    n = 2;
    cuadradoX0[0] = 0;
    cuadradoY0[0] = 0;
    cuadradoXinv0[0] = 1;
    cuadradoYinv0[0] = 1;

    cuadradoX0[1] = 0;    
    cuadradoY0[1] = 3;
    cuadradoXinv0[1] = 1;
    cuadradoYinv0[1] = 4;

    pointX = 0;
    pointY = 0;

}

void inputTest()
{
    //el problema estaba en que el scanf necesita llamar a una direccion de apuntador para recibir un int.
    // int in = 0;
    // scanf("%i", in);
    // printf("Cuadrado = %i\n", in );
    
    char * testPuntoX1; //= "0 0 0 0";
    int cuadradoX1;    
    int cuadradoY1;
    // scanf("%s", &testPuntoX1); //gives Segmentation failr: 11    
    // printf("test punto = %s\n", testPuntoX1 );

    fgets(testPuntoX1, 7, stdin);   //its giving bus error: 10
    printf("test punto = %s\n", testPuntoX1 );
    // scanf("%i", cuadradoX1);
    // printf("Cuadrado = %i\n", cuadradoX1 );
    // cuadradoX1 = atoi(strtok (testPuntoX1, " "));
    // printf("CuadradoX = %i \n", cuadradoX1);        
    // testPuntoX1 = strtok (NULL , " ");
    // cuadradoY1 = atoi(strtok (testPuntoX1, " "));
    // printf("CuadradoY = %i", cuadradoY1);


//  //taken from https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf
//     char *name;

//     /* Ask user for name. */

//     printf("What is your name? ");

//     /* Get the name, with size limit. */

//     fgets(name, 256, stdin);

//     /* Remove trailing newline, if there. */

//     if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n'))
//         name[strlen (name) - 1] = '\0';

//     /* Say hello. */

//     printf("Hello %s. Nice to meet you.\n", name); */
//GIVES SEGMENTATION FAILT: 11
}

int cuadradoMasCercano ()
{
    // input();
    //inputTest();
    presetCase();
    getCuadrados();
    calcularDistancias();
    sortDistancias();
    return 0;
}

void input ()
{
    printf("Introduzca los datos necesario para el programa");
    scanf("%i", &n);
    printf("n + %i \n", n);
    char * cuadrados [n];
    for(int i = 0; i < n; i++)
    {
        scanf("%s", cuadrados [i]);
        printf("Cuadrado[%i] = %s\n", i, cuadrados[i] );
        cuadradoX0[i] = atoi(strtok (cuadrados[i], " "));
        cuadrados[i] = strtok (NULL , " ");
        cuadradoY0[i] = atoi(strtok (cuadrados[i], " "));
        cuadrados[i] = strtok (NULL , " ");
        cuadradoXinv0[i] = atoi(strtok (cuadrados[i], " "));
        cuadrados[i] = strtok (NULL , " ");
        cuadradoYinv0[i] = atoi(strtok (cuadrados[i], " "));
        printf("CuadradoX = %i \nCuadradoY = %i", cuadradoX0[i] ,cuadradoY0[i]);
    }
    scanf("%s", referencia);
    pointX = atoi(strtok (referencia, " "));
    referencia = strtok (NULL , " ");
    pointY = atoi(strtok (referencia, " "));
    printf("puntoX = %i, puntoY = %i", pointX, pointY);
}

void getCuadrados()
{
    for (int i = 0; i < n; i++;)
    {
        if(cuadradoX0[i] < cuadradoXinv0[i] && cuadradoY0[i] < cuadradoYinv0[i])    //caso 1)
        {
            cuadradoX1[i] = cuadradoX0[i] + cuadrado 
        }    
        if(cuadradoX0[i] > cuadradoXinv0[i] && cuadradoY0[i] < cuadradoYinv0[i])
        if(cuadradoX0[i] < cuadradoXinv0[i] && cuadradoY0[i] < cuadradoYinv0[i])
        if(cuadradoX0[i] < cuadradoXinv0[i] && cuadradoY0[i] < cuadradoYinv0[i])
            
    }
}

double calculateDistance()
{
    for(int i = 0; i < n; i++)
    {
        if()   

    }
}
