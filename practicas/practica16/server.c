#include <stdio.h>
#include <sys/socket.h>

int main(){
    struct sockaddr_in serverAddress;//para inicializar mi direccion
    int serverSocket;
    int clientSocket;
    char *hello = "Hello World";

    serverSocket = socket(PF_INET, SOCK_STREAM, 0); //es UDP
    memset(&serverAddress, '0', sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;//igual que pf inet
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY;//igual que pf inet
    serverAddress.sin_port = htons(5000);//igual que pf inet
    
    
    //lleno la direccion de 0 porque quiereo hacer un binding a todas porque c no inicializa variable en 0
    //y entonces cuando haga el bind le digo que en todas las direcciones de este servidor escuche
    //unix es capaz de hablar ocnsigo ismo creando protocolos de red
    //crea sockets para hablar consigo mismo
    //STREAM 
    // DRAW ES UDP
    // RAW VOY YO SOLO
    bind(serverSocket, (struct sockaddr *)&serverAddress, strlen(sizeof(serverAddress)));//utiliza otro tipo de estrucutra que 
    //conincide con los dos primero pero el sadata es la suma desde el prta hasta adelante
    //soc addr_m
    // _len
    // sa_family
    // si n ps  estos ultimos dos los encapsula como data
    listen(serverSocket, 10);
    while(1){
        clientSocket = accept (serverSocket, (struct sockaddr*)NULL, NULL);//priero el socket, segundo el balck list, tercero el tamano de la lista
        write(clientSocket, hello, strlen(hello));
        read(clientSocket,clientMsg,1000);//el 1000 es el maximo de bytes
        printf("El cliente dice %s\n",clientMsg);
        giclose(clientSocket);//en ves de cerrarlo puedo mandar a esperar a que lea
    }

    // en terminarl
    // telnet localhost 5000 //5000 es le puerto

    return 0;
}