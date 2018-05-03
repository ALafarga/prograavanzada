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
	
	data = fopen(studentDb, "rb");
	while(1){
		fread(&myStudent, sizeof(Student), 1, data);
		if(feof(data)){
			break;
		}
		if(!strcmp(myStudent.lastName, lastName)){// que no sean iguales
			sprintf(myStudent.name, "Pedro");//ya actualice el nombre en memoria, falta en el archivo
			printf("name %s\n", myStudent.name);
			printf("lastName %s\n", myStudent.lastName);
			printf("id %d\n", myStudent.id);
			printf("grade %d\n", myStudent.cal);
			break;	//como ya hubo match break para que sigo buscando
		}
	}
	fclose(data);
	
	return 0;
}