#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 20

int varglobal;
sem_t sema; //tiene que ser globar

void *helloWorld(void *p)
{
    long id = (long)p;
    printf("Hello World %ld\n", id);
    sem_wait(&sema);//si el semaforo esta libre continua, sino espera 
    varglobal += 100;
    sem_post(&sema);//libera semaforo

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    long i;
    varglobal = 0;
    sem_init(&sema, 0, 1);//nombre,entre procesos,  entre hilos

    //sema = 0;

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(//atributos, tipo de planificador, round robin, conforme se an creadno los hilos
        //se le va dando cpu
            &threads[i],
            NULL,//atributos
            helloWorld,
            (void *)i);
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(
            threads[i],
            NULL);
        printf("varglobal = %d\n", varglobal);
    }

    return 0;
}