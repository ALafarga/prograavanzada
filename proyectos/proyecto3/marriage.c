#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct s{
    unsigned char used;
    unsigned short *preferencia;
    unsigned short count;
}prefItem_t;//prefItem_t||PrefItem

void recibirTablas(prefItem_t *,prefItem_t *, unsigned short);

//iterrar mujeres que quieres a sus maridos originales
void checkOnWomenHusband(prefItem_t *, prefItem_t *, unsigned short);

void iterateWomen(prefItem_t *, prefItem_t *, unsigned short);

void estado(prefItem_t *, prefItem_t *, unsigned short);

int main (){
    prefItem_t *mujeres;
    prefItem_t *hombres;
    short n,  //cantidad de parejas
        t;  //cantidad de test cases
    short i = 0;

    printf("Intoduzca la cantidad de parejas\n");
    scanf("%hu", &n);
    printf("n: %hu\n", n);

    mujeres = (prefItem_t *)calloc(n, sizeof(prefItem_t));//calloc inicializa las variables
    hombres = (prefItem_t *)calloc(n, sizeof(prefItem_t));
    for(i = 0; i < n; i++){
        mujeres[i].preferencia = (unsigned short *)calloc(n, sizeof(unsigned short));
        hombres[i].preferencia = (unsigned short *)calloc(n, sizeof(unsigned short));
    }

    //** printf("Iniciales:\n");
    //** estado(mujeres, hombres, n);
    
    recibirTablas(mujeres, hombres, n);
    //** printf("Despues de recibir datos\n");
    //** estado(mujeres, hombres, n);    
    checkOnWomenHusband(mujeres, hombres, n);
    //** printf("Despues de revisar muejeres asentadas\n");
    // **estado(mujeres, hombres, n);    
    iterateWomen(mujeres, hombres, n);

    return 0;
}

void recibirTablas(prefItem_t *mujeres,prefItem_t *hombres, unsigned short n){
    char i = 0 ,j = 0;
    
    for(i = 0; i < n; i++){
        printf("intoduzca las preferencias de la mujer %d una por una\n",i+1);
        
        for(j = 0; j < n; j++){
            printf("intoduzca las preferencias de la mujer %d.%d \n",i+1,j+1);
            scanf("%hu", &mujeres[i].preferencia[j]);
            // printf("Preferencia recibida %hu\n",mujeres[i].preferencia[j]);
            // printf("preferencias para mujer %d.%d: %hu  ,\n",i,j,mujeres[i].preferencia[j]);
            
        }
        printf("\n");
        
    }
    for(i = 0; i < n; i++){
        printf("intoduzca las preferencias del hombre %d una por una\n",i+1);
        for(j = 0; j < n; j++){
            printf("intoduzca las preferencias del hombre %d.%d \n",i+1,j+1);
            scanf("%hu", &hombres[i].preferencia[j]);
            // printf("Preferencia recibida %hu\n",hombres[i].preferencia[j]);
            // printf("preferencias para hombre %d.%d: %hu  ,\n",i,j,hombres[i].preferencia[j]);
            
        }
         printf("\n");
    }
    printf("informacion recibida:\n");
    printf("Mujeres:\n");
    
    for(i = 0; i < n; i++){
        printf("%d ",i+1);
        for(j = 0; j < n; j++){
            printf("%d ",mujeres[i].preferencia[j]);
        }
        printf("\n");
    }
    printf("hombres:\n");
     for(i = 0; i < n; i++){
        printf("%d ",i+1);
        for(j = 0; j < n; j++){
            printf("%d ",hombres[i].preferencia[j]);
        }
        printf("\n");
    }
}

//iterrar mujeres que quieres a sus maridos originales
void checkOnWomenHusband(prefItem_t *mujeres, prefItem_t *hombres, unsigned short n){
    // **printf("Entre a checkOnWomenHusband\n");
    unsigned short i = 0;
    for(i = 0; i < n; i++){
        if(mujeres[i].preferencia[0] == i+1){
            mujeres[i].used = 1;
            hombres[i].used = 1;
            //** printf("La mujer %d se queda con su esposo original\n",i+1);
            printf("!!!Marriage made man:%hu woman:%hu \n",i+1 ,i+1);
        }
    }
}

void iterateWomen(prefItem_t *mujeres, prefItem_t *hombres, unsigned short n){
    // **printf("Entre a iterateWomen\n");    
    char i = 0, aux = 0;
    short freeWomanCount = 0;
    // unsigned short *currentWomanList;
    unsigned short currentWomanCompare, //Guarda el gusto que quiere la mujer i que es lo que se va a comparar
                    currentManCompare,  //Guarda el hombre que se esta comparando o que esta ne la lista a comparar
                    //es la preferncia del hombre a comparar, esta es la que el hombre quiere, por lo que esta debe ser igual a i

                    mujerAEmparejar;    //Caso cuando las mujeres no encuantran match. Esta variable guarda la mujer que se 
                    //va a emparejar con los que quedan
    while(freeWomanCount < n){
        freeWomanCount = 0;
        for(i = 0; i < n; i++){//iterar todas las mujeres
            // **printf("mujer %d usada? %d\n",i+1,mujeres[i].used);
            // **printf("mujer %d cuenta %d\n",i+1,mujeres[i].count);
            if(mujeres[i].used == 0 && mujeres[i].count < n){//si la mujer no esta eligida revisa si hace match con el hombre que esta en apuntador (count)
                // **printf("Entre a if\n");
                //lista de las preferencias de la mujer i a revisar
                // currentWomanList = mujeres[i].preferencia;
                // **printf("Preferencia de Mujer %d a comparar %d\n",i+1,mujeres[i].preferencia[mujeres[i].count]);
                //mujeres que se va a revisar
                currentWomanCompare = mujeres[i].preferencia[mujeres[i].count];
                currentWomanCompare--;//porque los indices son base 0
                // **printf("hombre %d a comparar %d\n",mujeres[i].preferencia[mujeres[i].count],hombres[currentWomanCompare].preferencia[hombres[currentWomanCompare].count]);
                //hombre a revisar si concuerda con opcion de mujer
                currentManCompare = hombres[currentWomanCompare].preferencia[hombres[currentWomanCompare].count];
                currentManCompare--;
                // //**printf("currentWomanCompare %hu\n",currentWomanCompare);
                // //printf("currentManCompare %hu\n",currentManCompare);

                aux = 0;
                while(hombres[currentWomanCompare+aux].used==1){
                    ////printf("Hombre %d+aux:%d ya usado %d\n",currentWomanCompare+1,aux,hombres[currentWomanCompare+aux]);
                    mujeres[i].count++;
                    // //printf("Aumenta cuenta de mujer %d a %d por que su request ya esta usado\n",i+1,mujeres[i].count);
                    aux++;
                }
                // currentWomanCompare = mujeres[i].preferencia[mujeres[i].count]-1;
                
                // //printf("A comparar: current woman%d que quiere a %d con current man %d \n", i+1, currentWomanCompare+1, currentManCompare+1);
                if(mujeres[i].count < n && i == currentManCompare){//la mujer i debe estar en las preferencias del hombre a comparar
                    printf("!!!Marriage made man:%hu woman:%hu \n",currentWomanCompare+1 ,i+1);
                    //TODO TOASK profesor porque sale esto
                    // currentWomanList.used = 1; expression must have struct or union type
                    mujeres[i].used = 1;
                    hombres[currentWomanCompare].used = 1;
                }else if(mujeres[i].count < n){
              //      // printf("No se encontro pareja de %d. Se aumenta su cuenta que era %d\n",i+1,mujeres[i].count);
                    mujeres[i].count++;
                }
            }
            freeWomanCount += mujeres[i].used;
            if(mujeres[i].count >= n)
            {
                freeWomanCount ++;
            }
            //// printf("Free women: %d\n", freeWomanCount);
        }
    }
    for(i = 0; i < n; i++){//iterar los hombres que quedan solos
        //// printf("Entre a revisar todos los hombres solos por vez %d\n",i);
        //// printf("Hombre %d esta %d\n",i+1,hombres[i].used);
        if(hombres[i].used == 0){
            while(hombres[i].count < n && hombres[i].used == 0){
            //    // printf("While para liberar a hombre %d\n",i+1);
                mujerAEmparejar = hombres[i].preferencia[hombres[i].count];
              //  // printf("Revisa si mujer a emparejar %d esta usada: %d\n",mujerAEmparejar,mujeres[mujerAEmparejar-1].used);
                if(mujeres[mujerAEmparejar-1].used == 0){//-1 por que estan base 0
                    printf("!!!Marriage made al final man:%hu woman:%hu \n",i+1 ,mujerAEmparejar);
                    hombres[i].used = 1;
                    mujeres[mujerAEmparejar-1].used = 1;
                }else{
                    hombres[i].count++;
                }
            }
        }
    }
}

void estado(prefItem_t *mujeres, prefItem_t *hombres, unsigned short n){
    short i = 0, j = 0;
    printf("\n");
    
    for(i = 0; i < n; i++){
        printf("%d ",i+1);
        for(j = 0; j < n; j++){
            printf("%d ",mujeres[i].preferencia[j]);
            
        }   
        printf("\n");
        printf("usado %d \n",mujeres[i].used);
        printf("cuenta %d \n",mujeres[i].count);
    }
    printf("\n");
    
    printf("hombres:\n");
     for(i = 0; i < n; i++){
        printf("%d ",i+1);
        for(j = 0; j < n; j++){
            printf("%d ",hombres[i].preferencia[j]);
        }
        printf("\n");
        printf("usado %d \n",mujeres[i].used);
        printf("cuenta %d \n",mujeres[i].count);
    }
    printf("\n");
}