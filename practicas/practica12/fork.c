#include <stdio.h>
#include <unistd.h>
//Vamos a crear un proceso nuevo
int main()
{
	int pid;
	pid = fork();
	if (pid == 0)
	{
		execl("G:\My Drive\ITESM\12EneMay18\Programacion Avanzada\Repositorio\prograavanzada\practicas\practica12\hijo.exe", 
			"hijo.exe", (char*)0);
		printf("Hola soy el hijo mundo\n");
	}
	else
	{
		printf("Hola soy el padre\n");
	}
	

	return 0;
}