#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#define HASH_DEBUG "HASH_DEBUG"

void printDebug(char *msg){
    //n cuando no, y cuando si
    char *hashDebug = getenv(HASH_DEBUG);//regresa una cadena
    if(hashDebug != NULL && strcmp(hashDebug,"y") == 0){
        printf("%s\n", msg);
    }
}

unsigned
doHash(unsigned char *str, unsigned size)
//para saber en la posicion donde lo vamos a insertar
//puede regresar numeros mas grandes que el propio tamano del arrelglo entonces con un cast truena, removemos long
{
    unsigned hash = 5381;
    int c;

    while (c = *str++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % size;
}

void hashInit(HashInt *hash, int size)
{
    hash->size = size;
    hash->data = (HashElement *)calloc(size, sizeof(HashElement));
};

static hashDoInsert(HashInt *hash, char *key, int value)
{
    char errorMessage[255];
    printDebug("doHash");
    //doHash
    int index = doHash(key, hash->size);
    //doHash 2
    printDebug("doHash2");
//    HashElement currentHashElement = hash -> data[index];    //no esta bien inicializada
    HashElement * currentHashElement = &(hash -> data[index]);    //para que no haga copia sino que obtenga la direccion
    
    //index %d, index
    sprintf(errorMessage, "index %d", index);
    printDebug(errorMessage);
    if (currentHashElement->elements == NULL)
    {
        printDebug("CHECKING DATA");
        //checking data\n
        //inicializado vector cuando es Null que no aapunta a nada
        currentHashElement->elements = (Element *)malloc(2*sizeof(Element));
        currentHashElement->count = 0;
        currentHashElement->length = 2;
        //////count sirve para insertar los elements
        //////tenemos que comparar coutn con length para saber cuando lo tenemos que aumentar
    }
    if( currentHashElement->length == currentHashElement->count){
        currentHashElement->length *= 2;
        currentHashElement->elements = realloc (currentHashElement->elements,
                                                currentHashElement->length * sizeof(Element));
    }
    //assigning
    printDebug("Assigning");
    currentHashElement->elements[currentHashElement->count].key = strdup(key);
    currentHashElement->elements[currentHashElement->count].value = value;
    currentHashElement->count += 1; 
    //completed
    printDebug("Completed");
}

static void hashDoUpdate(HashInt *hash, char *key, int value){
    int pos = doHash(key, hash->size);
    int i;
    Element * currentElements = hash->data[pos].elements;
    int currentElementsLength = hash->data[pos].count;

    for(i = 0; i < currentElementsLength; i++)
    {
        if(strcmp(key, currentElements[i].key) == 0){
            //si encuentro el valor creo un bloque d ememoria dinamico para que exista y este dentro de mi heap
            //sino con el return iba a desaparecer
            currentElements[i].value = value;
            break;
        }
    }
}


void hashInsert(HashInt *hash, char *key, int value)
{
    int * oldValue = hashGet(hash, key);//nos busca si el valor ya existe
    if (oldValue == NULL){
        hashDoInsert(hash, key, value);
    }else{
        hashDoUpdate(hash,key,value);
    }
};

int * hashGet(HashInt *hash, char *key)
{
    int pos = doHash(key, hash->size);
    int i;
    Element * currentElements = hash->data[pos].elements;
    int currentElementsLength = hash->data[pos].count;
    int *value = NULL;

    for(i = 0; i < currentElementsLength; i++)
    {
        if(strcmp(key, currentElements[i].key) == 0){
            //si encuentro el valor creo un bloque d ememoria dinamico para que exista y este dentro de mi heap
            //sino con el return iba a desaparecer
            value = (int *) malloc(sizeof(int));
            *value = currentElements[i].value;
            break;
        }
    }
    return value;
};
