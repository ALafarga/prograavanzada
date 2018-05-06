Union

crea un bloque de la unidad mas grande que hay
entonce es el mismo bloque de memoria "compartida" y si escribo en ella dos veces se sobres escribe

union ip{
    char a[4]
    int dir
}
entonces si quiero usar la direccion completa uso dir si quiere algun octeto uso a

el primer uso 

union j {
    struct s;
    struct sr;
}

struct s{
    char name [20]
}

struct sr{
    char name[20]
    20 lastname[]
}

entonoces reciben j las funciones pero adentro pueden dirigirse solo al nombre o al nombre y apellido



Demonios

imprimimr
cups

se conecta con todas las impresoras disponibles
e imprie

Sendmail
hay un proceso que se comunica con otra computadora manda los datos y el correo llega magicamente

entonces en la compu se teclea top
ps -fea

hay un monton de procesos corriendo donde la mayorea son demonios que estan esperando para actuar

te ayudan a que la coputadora funcione como y olo espero

asincronos
init es su padre
backgound
entrada/salida no va a consola
    no estan a stdout
    algunos estan a error
    o estan a archivos

entonces cuando arranco un demoio lo primmero es cerrar su entrada y salida y lo mandas a un carchivo
entones lo bonito d elo demonios queesque no nos debemos dar cuenta de su existencia

Fork

Exec

un padre 

el so existe un o existe
requiere cpu para poder correr
entonces el so para darse cpu 
entonces en el tiempo que se le da al padre se usa para limpiar la memoria de lso hijos
entonces si terminas al padre y no limpiarste a los hijos no existe forma de limmpiar la RAM que los hijos estan utilizando entonces se puerde ese pedazo de memoria
entonces si un padre muere todos sus hijos pueden morir

algo que hacen muchos so , los hijos zombies se los pasan a init
y entonces cuando le dan tiempo a init se limpia ell espacio d ememoria de los hijos

llamadas a sistemas
el tiempo para abir un archivo lo toma del proceso que esta corriendo actualmente


Entonces para hacer un demonio necesitamos que inti nos adopte

vamos a crear un proceso que tendra un hijo que tendra un hijo
matamos al padre y al abuelo y el nieto se pegara a init

en el proceso de crearlos fork

exec es para cambiar el codigo
fork es para crear una cadenita


los demonios solo los puede matar el so

porque son los que hacen que tu maquina funcione


