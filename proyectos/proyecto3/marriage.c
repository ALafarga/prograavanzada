#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct s{
    unsigned char used;
    unsigned short *preferencia;
    unsigned short count;
}prefItem_t;//prefItem_t||PrefItem

unsigned short recibirTablas(prefItem_t *,prefItem_t *);

//iterrar mujeres que quieres a sus maridos originales
void checkOnWomenHusband(prefItem_t *, prefItem_t *, unsigned short);

void iterateWomen(prefItem_t *, prefItem_t *, unsigned short);

int main (){
    prefItem_t *mujeres;
    prefItem_t *hombres;
    short n,  //cantidad de parejas
        t;  //cantidad de test cases
    short i = 0;

    mujeres = (prefItem_t *)calloc(n, sizeof(prefItem_t));//calloc inicializa las variables
    hombres = (prefItem_t *)calloc(n, sizeof(prefItem_t));
    for(i = 0; i < n; i++){
        mujeres[i].preferencia = (unsigned short *)calloc(n, sizeof(unsigned short));
        hombres[i].preferencia = (unsigned short *)calloc(n, sizeof(unsigned short));
    }

    n = recibirTablas(mujeres, hombres);

    return 0;
}

unsigned short recibirTablas(prefItem_t *mujeres,prefItem_t *hombres){
    unsigned short n;
    char i = 0 ,j = 0;
    char * preferencias;
    printf("intoduzca la cantidad de parejas\n");
    scanf("%hu", n);
    for(i = 0; i < n; i++){
        printf("intoduzca las preferencias de la mujer %d separadas por ,\n",i);
        scanf("%s", preferencias);
        for(j = 0; j < n; j++){
            mujeres[i].preferencia[j] = (unsigned short)strtok(preferencias,",");
        }
    }
     for(i = 0; i < n; i++){
        printf("intoduzca las preferencias del hombre %d separadas por ,\n",i);
        scanf("%s", preferencias);
        for(j = 0; j < n; j++){
            mujeres[i].preferencia[j] = (unsigned short)strtok(preferencias,",");
        }
    }
    return n;
}

//iterrar mujeres que quieres a sus maridos originales
void checkOnWomenHusband(prefItem_t *mujeres, prefItem_t *hombres, unsigned short n){
    unsigned short i = 0;
    for(i = 0; i < n; i++){
        if(mujeres[i].preferencia[0] == i){
            mujeres[i].used = 1;
            hombres[i].used = 1;
        }
    }
}

void iterateWomen(prefItem_t *mujeres, prefItem_t *hombres, unsigned short n){
    unsigned short i = 0;
    unsigned short currentWomanCompare, currentManCompare;
    for(i = 0; i < n; i++){//iterar todas las mujeres
        if(mujeres[i].used == 0){//si la mujer no esta eligida revisa si hace match con el hombre que esta en apuntador (count)
            currentWomanCompare = mujeres[i].preferencia[mujeres[i].count];//lista de la lista de preferencias de mujeres en la que se va a revisar
            currentManCompare = hombres[currentWomanCompare].preferencia[hombres[currentWomanCompare].count];
            printf("currentWomanCompare &hu\n",currentWomanCompare);
            printf("currentManCompare &hu\n",currentManCompare);
            
            if(currentWomanCompare == currentManCompare){
                printf("Marriage made man:%hu woman:%hu \n",currentManCompare ,i);
            }
        }
    }
}