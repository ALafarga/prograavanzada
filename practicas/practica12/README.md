PRACTICA 12
Vamos a crear un proceso nuevo


Notas:
Las variables del heap estan ahi hasta que les haga freee y desde el heap tengo acceso a toda la ram no immporta la cantidad de procesos

El stack se muere cuando se llena
Variables pequenas van al stack las grandes al heap
Codigo esta en RAM

Meta
	Informacion que se guarda para controlar el programa
	PID	Tabla de procesos con un ID para cada uno
	McMem	Apuntador a la memoria
	Recursos	Lleva un tracking del so para entenderlo
	Estado	
	

Crear
Nuevos procesos
	Como usuario doy doble click, SO crea nuevo codigo
	Hay dos llamadas para sistema codigo hacer un nuevo proceso 
		Fork       hace clones
		Exec
	Clone
	P1                 y                      P2
	Porque hacerlo
		Por eficiencia
		
	Exec 
		Reemplaza el codigo que tienes en uno de los clones al otro

Porque quiero tener varios proceso como desarrollador
	Desarrollador gandalla crea muchos procesos para procesar lo que tiene que hacer
	Pero es una sola aplicacion con varios esclavos trabajando
		Otro proble como los comunico
		Aqui aparecen los IPC Inter Process Communication
			Signal
			Mailboxes
			Shared Memories (Mman)
			
			
			
			Gcc -o fork.exe fork.c
			
			
	Fork es la unica funcion que regresa dos valores, el padre regresa el id del hijo y el hijo regresa 0
	
Signal
	Un proceso le manda una senal a otro,
	No es otra cosa que un numero
	Entonces P3 va a tener una lista de si le llega la senal 4 voy a hacer algo
	Me sirve para indicarle al proceso que haga ciertas cosas
	SO ya tiene varias senales predefinidas
		Las utiliza para controlarlo
		Es la forma en la que le dice stop
		O para matarlo con ctrl+c le estas mamndando una senal y no importa que termina
			Es la forma en que lo detiene
		Ctrl z es un stop, lo pones a dormir, no pide mas cpu pero todos los recursos que estan ocupando estan ahi, lo unico que hace es que no se executa mas
		
		
		Kill -l 
			Listado de las senales para los procesos
			Stop
			Cont    contraria de stop
			Kill   no se puede sobreescribit
			Term    terminalo de buena onda, me podria ignorar
			
Si le mando la senal de freeze
		Ps -fea |
		Ps es un comando que me va a hacer un listado de los procesos de mi cpu
		Fea es para agregarle todo lo habido y por haber
		Ps -fea | 
		| me va a buscar un patron 
		Ps -fea | grep firefox
		
		99648  id del firefox
		Kill -s STOP 99648  
			Firefox es un cuerpo sin vida
			
			Zombie es cuando muere 
			Todo empieza con la muerte de tu padre
			
		Kill -s CONT 99648
		Kill -s KILL 99648
		
		
		Signal (#, functionName);
		SIGUSR1 Y SIGUSR2 estan libres, no hay una funcion asociada, las demas tienen asociadas y se pueden sobreescribir, la unica que no se puede sobrescribir es Kill
		
		
		Puedo usar kill par amandar senales
		Kill -s USR1 434 //usr1 es la que usamos… SIGUSR1
		Y con esto va a correr el cogidgo de signal
			Debe aparecer gor signal 30
			
		Hay ds tipos de procesos, asinconos y sincronos
		Cuando corro en la terminal lo hace sincrono pero si lo corro como 
		./signal.exe &
			Lo va a correr y va a regresar
			
		Si el padre quiere esperar el hijo se usa wait()
		
