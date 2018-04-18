#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <strings.h>
#include <ctype.h>

//no funciono en windows tengo que quitarle la negacion para decirle que imprima o que no
#define PRINTDEBUG(...) \
    do \
    { \
        char *debug; \
        debug = getenv("DEBUG"); \
        if (debug != NULL && !strcmp(debug, "y")) \
        { \
            fprintf(stderr, __VA_ARGS__); \
        } \
    } while (0)

int MAXN = 30;

int Num[30], Ordenados[30];//num guarda los elementos de cada partido 
						 //ord guarda el orden de Num descendente

int cmpfunc(const void *_a, const void *_b) {

	int a = *(int *)_a,
		b = *(int *)_b;

	return (Num[b] - Num[a]);
}

int main() {
	//No funciono en windows
	//char *deb = getenv("DEBUG");
	//fputc(deb, stdout);
	//fprintf(stderr, "debug = %s\n", deb);
	PRINTDEBUG("DEBUG: %s\n", debug);
	int aux;

	FILE *input = fopen("input.txt", "r");
	//FILE *output = fopen("output.txt", "w");

	int casos=0;//casos
	//scanf("%d", &casos);//number of cases
	aux = fgetc(input);
	do {
		if (isdigit(aux)) {
			casos=casos*10 + aux - 48;//de ascii a int
		}
	} while (isdigit(aux = fgetc(input)));
	PRINTDEBUG("Casos: %d\n", casos);
	//fputc(casos, stdout);
	//fputc("\n", stdout);
	int i = 0;
	for (i = 1; i <= casos; i++) {//recorre los casos
		memset(Num, 0, (sizeof Num)); //restart arreglo
		memset(Ordenados, 0, (sizeof Ordenados));
		if (feof(input))
		{
			break;
		}
		
		int N = 0, canTotal = 0;//N es la cantidad de partidos canTotal es la cantidad 
		//de senadores en la sala

		//scanf("%d", &N);//cantidad de partidos
		aux = fgetc(input);
		do {
			if (isdigit(aux) ){
				N = N*10 + aux-48;//de ascii a int
			}
		} while (isdigit(aux = fgetc(input)));
		

		//fprintf(stderr, "N = %d\n", N);
		PRINTDEBUG("\nN = %d\n", N);
		//fprintf(stderr, "\n");
		PRINTDEBUG("\n");
		int j = 0;
		for (j = 1; j <= N; j++) {
			//scanf("%d", &Num[j]);//cantidad que hay en cada partido
			//Num[j] = fgetc(input);
			aux = fgetc(input);
			do {
				if (isdigit(aux)) {
					//Las posiciones de Num referencian los partidos y el contenido son 
					//la cantidad/partido
					Num[j] = Num[j] * 10 + aux-48;

				}
			} while (isdigit(aux = fgetc(input)));

			PRINTDEBUG("Num[%d] = %d\n", j, Num[j]);
			//fprintf(stderr, "Num[%d] = %d\n", j, Num[j]);

			canTotal = canTotal + Num[j];//suma total de personas
			//fprintf(stderr, "canTotal = %d\n", canTotal);
			PRINTDEBUG("canTotal = %d\n", canTotal);
			Ordenados[j] =	j;//posicion del arreglo que se esta usando, se usara para sort
			PRINTDEBUG("Ord = %i, j: %d\n", Ordenados[j], j);
			//fprintf(stderr, "Ord = %i, j: %d\n", Ordenados, j);
		}
		//fprintf(stderr, "\n");
		PRINTDEBUG("\n");
		printf("Case #%d:", i);
		
		//sort(Ord + 1, Ord + N + 1, Cmp);
		//mayor a menor para agarrar primero los que estan de mayor
		qsort(Ordenados + 1, N, sizeof(Num[1]), cmpfunc);//ordena desde mayor a menor
		while (Num[Ordenados[1]] != Num[Ordenados[2]]) {//Cuando sean diferentes las 
			//cantidades vamos a sacar personas
			printf(" %c", Ordenados[1] - 1 + 'A'); //para imprimir A que es 65 el 
			//Ordenados[1] =1 - 1 + 65
			//imprime q elemento la de la fila mas grande
			Num[Ordenados[1]] --;//resta del partido que se esta sacando
		}
		int k;
		for (j = 3; j <= N; j++) {//saca todos los del partido con menor cantidad
			for (k = 1; k <= Num[Ordenados[j]]; k++) {
				printf(" %c", Ordenados[j] - 1 + 'A');
			}
		}
		for (j = 1; j <= Num[Ordenados[1]]; j++) {//Las columnas que quedan son de la 
			//misma altura asi que imprimo ambos hasta que se terminen
			printf(" %c%c", Ordenados[1] - 1 + 'A', Ordenados[2] - 1 + 'A');
		}
		printf("\n");
	}
}