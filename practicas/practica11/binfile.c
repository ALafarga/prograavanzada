#include <stdio.h>
//si no pongo el typedef tengo que poner la palabra struct en todos lados
typedef struct s {
	char name [20];
	char lastName[20];
	unsigned int id;	//4 bytes
	unsigned char cal;
} Student;

int main() {
	char *studentDb = "studentDb.data";
	FILE *data; // = fopen(studentDb, "wb");	//b es de binario no quiero que me lo interprete, w es para sobrescribir
	//la b siempre tiene que ir al final !!!
	Student pAvanzada[5];
	int i;
	for(i = 0; i < 5; i++) {
		sprintf(pAvanzada[i].name, "student%d", i);
		sprintf(pAvanzada[i].lastName, "Perez%d", i);
		pAvanzada[i].id = i * 20;
		pAvanzada[i].cal = i * 7;
	}
	
	//no hay que abrir los archivos hasta que ya los vaya a utilizar para que no se bloqueen
	data = fopen(studentDb, "bw");
	fwrite(pAvanzada, sizeof(Student), 5, data);
	fclose(data);
	return 0;
}