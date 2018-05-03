#include <stdio.h>
#include <omp.h>

#define SIZE 2000

//export OMP_NUM_THREADS=[NUM_THREADS]
// gcc -o openmp.exe openmp.c -fopenmp
int main()
{
    //open mp tiene una variable en env que controla cuantos hilos
    //por default con los cores
    #pragma omp parallel
    {
        printf("Hola mundo\n");
    }

    return 0;
}