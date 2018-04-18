/*		SAVE HUMANITY
Lo primero que hay que hacer es leer los strings a comparar.
Hacemos un for loop dependiendo de cuantos test cases tenemos
Despues hacemos un loop para leer las siguientes dos strings (p,v) y guardamos el tamano de p y v
Si v es mayor que p no puede haber match
Dentro de un loop recorreremos desde 0 hasta la diferencia de tamano p y tamano de v que son la cantidad
de opciones que tenemos que nos puede dar el virus
Dentro de este loop haremos otro para commparar el luegar del apuntador de p con el caracter de v
que estamos comparando y si hay match aumentamos una bandera de comprobacion siempre que se cumpla
la comparacion de caracteres
Una vez que terminamos comprobomos que la bandera donde guardamos los aciertos se mayor que uno o menor
que el tamano de v menos 1
Si se cumple tenemos un enfermo e imprimimos el apuntador de p que se esta compmrobando
Sino se cumple esto entonces no hay match
*/

#include <stdio.h>
#include <string.h>

int test = 0,
contador = 0, //contendra la cantidad de caracteres iguales
enfermo = 0, //boolean que nos dira si se hizo match o no
tamanoP = 0,
tamanoV = 0,
character;//comodin para comparar

int i = 0,
j = 0,
k = 0;

char p[100001],
v[100001]; //tamanos de los caracteres 10^5


int main() {
	scanf("%i", &test);
	scanf("%s", p); //no tenemos que poner especificadores porque 
	tamanoP = strlen(p);
	scanf("%s", v);
	tamanoV = strlen(v);
	for (i = 0; i < test; i++) {

		for (j = 0; j <= (tamanoP - tamanoV); j++)
		{
			enfermo = 0;//reinicializamos 
			for (k = 0; k < tamanoV; k++)
				if (p[j + k] == v[k])
					contador++;

			if ((contador == tamanoV) || (contador == (tamanoV - 1)))
			{
				printf("%d ", j);
				enfermo = 1;
			}
		}
		if (!enfermo) {
			printf("No Match!");
		}
		printf("\n");
	}

	return 0;
}