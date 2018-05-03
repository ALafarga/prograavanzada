#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 30

void *helloWorld(void *p)
{
    long id = (long)p;
    printf("Hello World %ld\n", id);

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    long i;

    for (i = 0; i < NUM_THREADS; i++)   //inicializa y corre threads
    {
        pthread_create(
            &threads[i],    //referencia al hilo
            NULL, //atributos por default del hilo
            helloWorld, //funcion que va a ejecutar el hilo
            (void *)i); //recibe como parametro la funcion de arriba
    }

    for (i = 0; i < NUM_THREADS; i++)
    //sin esto se quedan vivos todos los hilos
    // en cuanto los crea termina
    {
        //espera por todos los hilos terminos
        //no sabemos en que orden terminan
        pthread_join(//funcion dentre de pthread.
            threads[i],
            NULL);
    }
    return 0;
}