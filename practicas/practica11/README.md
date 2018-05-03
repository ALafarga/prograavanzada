Replace con entradas del main
argv
es un arreglo de apuntadores a los string que recive de entrada separados por un espacio

Vamos a buscar la palabra a reemplazar y al hacerlo utilizaremos un while para comparar la palabra completa
NOTA: Siempre hay que checar por el EOF porque puede aparecer donde sea

si encontraos la palabra comparamos la longitud del string con el iterador
	si son iguales entonces tenemos que reemplazar la palabra y reajustar el apuntador del character
	en el que vamos con un fseek

Tambien tenemos que guardar el caracter en el que vamos porque al leer character para compararlo con la palabra a reemplazar 
se pierde pues avanzamos el apuntador y al imprimir con fputc si no tenemos el firstCharacter se pierde esa letra.


Lectura de archivos binarios

struct c{
	int a;
	char b;
	short g;
	char ar[4];
}

short y long son modificadores de datos entonces short long no existe
int es de 4 bytes
char es de 1 bytes
short 2 bytes
char [4] 
total 11 bytes
entonces si son 32 bites me sobran 2 bytes d ememoria que no se pueden usar


RAM 32 bits

	| | |s|		s= sobra y se desperdicia
b	| |c| |
a	| | | |


fwrite
fread

permiten ambos trabajar a nivel de bytes

En internet podemos abrir un archivo con el 
HexEd.it

EL INFINITO ES EL LIMITE!