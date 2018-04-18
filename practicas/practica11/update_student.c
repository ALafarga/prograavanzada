#include <stdio.h>
#include <string.h>

typedef struct s {
	char name [20];
	char lastName[20];
	unsigned int id;	//4 bytes
	unsigned char cal;
} Student;

int main (){
	Student myStudent;
	char *studentDb = "studentDb.data";
	char *lastName = "Perez2";
	FILE *data;
	
	data = fopen(studentDb, "r+b");
	while(1){
		fread(&myStudent, sizeof(Student), 1, data);
		if(feof(data)){
			break;
		}
		if(!strcmp(myStudent.lastName, lastName)){// que no sean iguales
			sprintf(myStudent.name, "Pedro");//ya actualice el nombre en memoria, falta en el archivo
			//fread mueve el flujo entonces puedo user fseek, uso current y me regreso 1
			fseek(data, -1*sizeof(Student), SEEK_CUR);
			fwrite(&myStudent, sizeof(Student), 1, data);
			
			break;	//como ya hubo match break para que sigo buscando
		}//"r+" si el archivo no existe es erro
		//"w" si no existe te lo crea pero si ya existe te lo borra
		//"a" siepre va a estar agregando pero entonces hago un rewind
		//"a+" te va a mandar al final, si no existe lo crea
	}
	fclose(data);
	
	return 0;
}