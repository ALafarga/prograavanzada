#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

typedef struct s {
	char name[20];
	char lastName[20];
	unsigned int id;	//4 bytes
	unsigned char cal;
} Student;


int main() {
	char *fileName = "studentDb.data";
	int fd = open(fileName, O_RDWR);
	int id;
	char name[20];

	//busca donde corre el programa
	Student *pAvanzada = (Student *)mmap( //limitante de mmap es que le tienes que decir cuantos
										  //bytes quieres de ese bloque de memoria.
		NULL,
		5 * sizeof(Student),
		PROT_READ | PROT_WRITE,
		MAP_FILE | MAP_SHARED,//SOLO ESTE PROCESO TENDRA ACCESO A ESTE ARCHIVO
		fd,
		0
	);

	for(int i = 0; i < 4; i ++) {
		printf("Provide id, new name \n");
		scanf("%d %s", &id, name);
		strcpy(pAvanzada[1].name, "Pedro");
		msync(&pAvanzada[1], 5 * sizeof(Student), MS_SYNC);

	}

	munmap(pAvanzada, 5 * sizeof(Student));
	close(fd);

	return 0;
}