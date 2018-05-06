#include <stdio.h>
typedef struct s{
    unsigned char used;
    unsigned short *preferencia;
    unsigned short count;
}prefItem_t;//prefItem_t||PrefItem

void checkOnWomenHusband(prefItem_t *mujeres, prefItem_t *hombres, short n){
    short i = 0;
    for(i = 0; i < n; i++){
        if(mujeres[i].preferencia[0] == i){
            mujeres[i].used = 1;
            hombres[i].used = 1;
        }
    }
}

void iterateWomen(prefItem_t *mujeres, prefItem_t *hombres, short n){
    short i = 0;
    for(i = 0; i < n; i++){
        if(mujeres[i].used == 0){
            if(hombres[
                mujeres[i].preferencia[mujeres[i].count]
                ].preferencia[[mujeres[i].preferencia[mujeres[i].count]]] == mujeres[i].preferencia[mujeres[i].count]){

            }

        }
    }
}

int main (){
    prefItem_t *mujeres;
    prefItem_t *hombres;
    short n,  //cantidad de parejas
        t;  //cantidad de test cases
    short i = 0;

    mujeres = (prefItem_t *)calloc(n, sizeof(prefItem_t));//calloc inicializa las variables
    hombres = (prefItem_t *)calloc(n, sizeof(prefItem_t));
    for(i = 0; i < n; i++){
        mujeres[i].preferencia = (short *)calloc(n, sizeof(short));
        hombres[i].preferencia = (short *)calloc(n, sizeof(short));
    }


    return 0;
}