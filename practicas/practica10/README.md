
En esta practica veremos como establecer una estructura para poder utilizar el debug referenciado a una variable de entorno
    variable de entorno: son variables que no cambian cuando se apaga o prende la computadora. De esta forma podremos activar y desactivar el modo de debug de todos nuestro proyectos, practicas o katas siguientes. 

Para poder utilizar estas variables en el lenguaje C se utliza getenv(args); // args es el nombre de la variable.

Para poder hacer nuestra propia funcion que se utlice como si fuera un print utilizaremos MACROS
Las MACROS es codigo que sera introducido al codigo en tiempo de compilacion, esto significa que no tendremos que escribir una funcion completa cada vez que se utilizara la funcion, el problema es que si hay errores en la funcion no se veran reflejados en el IDE.

Para realizar macros se utiliza el prefijo #define seguido del codigo a utilizar
ex: #define PRINTDEBUG(...) \
    do \
    { \
        char *debug; \
        debug = getenv("DEBUG"); \
        if (debug != NULL && !strcasecmp(debug, "y")) \
        { \
            fprintf(stderr, __VA_ARGS__); \
        } \
    } while (0)

    En este ejemplo utilizamos la vieja tecnica del do while 0 para poder utilizar nuestro codigo como una funcion real, de esta forma tenemos que terminar con un ";" para que nuestro codigo funcione
    ex:
        PRINTDEBUG("character = %c\n", character);

    Entonces en este caso con la variable __VA_ARGS__ estamos pasando todos los parametros que se necesiten, esto significa que podemos pasar n cantidad de argumentos.
        Como nuestra macro usa la funcion de fprinf(output, string, var);, le pasamos el string como lo que queremos imprimir y la variable que queremos utilizar.
        Asi simulamos la funcionalidad de un printf basico que solo se ejecutara si la variable de ambiente DEBUG es igual a 'y'
    
    Otro punto a denotar de las MACROS es que necesitamos poner una diagonal inversa (\) para que nuestro compilador sepa que no debe agregar un \n cuando nosotros damos enter, y de esta forma podemos escribir un codigo mas legible para cualquiera que lea el codigo.

    Esta tecnica se conoce como INLINING CODE


Para poder leer de una entrada utilizaremos la funcion fgetc que lee de una entrada standard que en este caso sera llamada con la funcion cat desde la terminal
Con la funcion feof podremos saber cuando llegamos al final de la linea y copiaremos lo que recivamos de la entrada.
Utilizaresmos la funcion llamada en forma de MACRO de printdebug que ya explique anteriormente.

La funcion que usaremos para indicar cual sera la entrada y la salida sera:
    Cat input.c | ./input.exe 2> archivo.txt 1> buena.txt

    Indica que lo que lea del archivo input.c sera enviado como entrada al input.exe el cual a su vez mandara la segunda salida estandard, indicado con el 2> a un documento llamado archivo.txt y a la salida estandard 1, indicado como 1> a buena.txt.

    //Si se utiliza el simbolo >> significa que queremos una concatenacion, es decir lo que vaya a escribir sera insertado al final del archivo.
    Cuando se utiliza > significa que si el archivo ya existe sera sobreescrito.

Cuando hablamos de salidas y entradas estandar nos referimos a la generalidad de los procesos donde todo proceso tiene una entrada estandar indicada con un 0 que por lo general es el teclado, una salida estandar indicada con un 1 que es el monitor y una salida estandar de error que por lo general es tambien el monitor. 
Esta es la teoria a la que se refieren los numeros 1 y 2 que utilizamos para indicar la salida del executable que lee lo que sea que entra y lo escribe.