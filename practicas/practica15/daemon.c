#include <stdio.h>
#include <unistd.h>

int main(){
    //el so no puede terminar al nieto porque no existe cuando lo matan
    //el segundo crea a un hijo y muere y entonces se queda en while corriendo
    int pid = fork();
    if(pid == 0){
        pid = fork();
        if(pid == 0){
            // printf("Soy el daemon\n");
            //Para precaucion y que no se sepa que existo cierro las entradas y salidas
            fclose(stdout);
            fclose(stdin);            
            while(1){

            }
        }
    }
//si solo pongo 1 hijo estoy aventando un volado porque si el so es muy rapido alcanza a detectar al hijo
//pero creando dos le doy un poco mas de delay y entonces ese proceso ya se queda vivo
    return 0;
}