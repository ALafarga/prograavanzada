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
	int fd = open(filename, O_RDWR);
		//busca donde corre el programa
	Student *pAvanzada = (Student *) mmap( //limitante de mmap es que le tienes que decir cuantos
		//bytes quieres de ese bloque de memoria.
		NULL,
		5 * sizeof(Student),
		PROT_READ | PROT_WRITE,
		MAP_FILE | MAP_PRIVATE,//SOLO ESTE PROCESO TENDRA ACCESO A ESTE ARCHIVO
		fd,
		0
		);
	
	printf("First Studet %s\n", pAvanzada[0].name);
	strcpy(pAvanzada[1].name, "Pedro");
	printf("Second Studet %s\n", pAvanzada[1].name);
	msync(&pAvanzada[1], 5 * sizeof(Student), MS_SYNC);
	munmap(pAvanzada, 5 * sizeof(Student));
	close(fd);

	return 0;
}