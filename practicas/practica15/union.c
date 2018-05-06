#include <stdio.h>

typedef union i {
    unsigned char parts[4];
    unsigned dir;//declarado como unt autoatico
}IpAddress;

int main (){
    IpAddress myAddress;
    myAddress.parts[0] = 127;
    myAddress.parts[1] = 0;
    myAddress.parts[2] = 0;
    myAddress.parts[3] = 1;

    // printf("The number is %d \n", myAddress.dir);
    //esto imprimio: The number is 16777343
    printf("The number is %ud \n", myAddress.dir);
    myAddress.dir +=1;
//little o big endian 
//en el little endian 
//si sumo uno y se afecta el byte 0 es little endian
//si se afecto al 3 es que es big endian
    printf("The %d %d \n", myAddress.parts[0],myAddress.parts[3]);
//imprimio The number is 16777343d
//The 128 1
//entonces es little endian porque afecto al menos significativo
//big endian 2^2 2^1 2^0
//little endian 2^0 2^1 2^2

    return 0;
}