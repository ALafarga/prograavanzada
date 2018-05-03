get host by name

DNS regresa ip del nombre
si el so ya habia reguntando y esta en cache e la regresa sino se bloquea y pregunto


puertos
smtp 25
gttp 80
https 443

cada servicio se identifica por un numero
 puerto 80

entoncs lo siguiente es crear un canald e comunicacion

unix mac, etc
excepto windows

la forma que tengo para escribir archivos, ya hay un API, que fon un file descriptor le pongo un write etc

entonces el linux es muy bonito ocmo reutilizaron el codigo que tenian
entonces para el write
write(fd,...,...)
etonces en la red el mo mismo creo una conexion y mando bytes
les da igual si vas a escribir un carchivo o si vas a escribir en una cnoneccion
entonces necesitamos crear esa conexion que se conoce como socket
que va a hacer la conexion de internet con un file descriptor, que es donde puedo escribir o leer

write(socket,.. ,..,..)
read(socket,...,..,,)

connect(socket, id y puerto a conectar) y se encarga de hacer el encapsulamiento de la conexion

entonces el servidor me rechaza y eventualmente termina el connect, timeout, no se pudo crear el socket o lo que sea

PARTE OSCURA DE C
parte d emanejos de errores

casi todas la fucniones solo pueden regresar unvalor
carecen de otra forma de indicar los erroes
entonces lo que se les occurio por ingeniosos o porque abusaron del elnguaje

Cerrores
errorno     error number, variable global, no puedo regresar cuando hay un error pero le puedo poner un numero y con esta forma indico que fue lo que fallo


del lado del servidor loq ue tengo que hacer es un 
bind
cuando alguien pregunte por un puerto mandame llamar
eso es un bind
la unica razon por la que falle es que el puerto ya lo este usando alguien mas
entonces despues d ehacer bind
y que falle 
el server utiliza listen()
se va a dormir y queda en espera de que alguien se conecte a esa parte
while()
el so del servidor me dara toda la infomracion de la conexion.
despierta el proceso que hizo bind y lo primero es aceptar la ocneccion
socket accept() regresa un socket 

write and read
entonces se la pasan escribiendo y deas
si tiene un while seguira durmiendo y demas

el problema con este approach es que se puede quedar platiando y no atender a nadie mas
entonces lo normal es que se haga un fork para crear otro hilo 
