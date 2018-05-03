#include <stdio.h>

typedef struct d {
    unsigned char day:5;
    unsigned char month:4;
    unsigned short year;
} Date;

int main (){
    Date today = {26,4,2018};
    printf("Today is %d/%d/%d \n", today.day, today.month,today.year);
    //si al dia le ponemos una suma mayor que el dia hara overflow y 
    //se reseteara
//    today.day += 6;
 //   printf("Today is %d/%d/%d \n", today.day, today.month,today.year);

    if(today.day ^ 26 == 0){
        printf("Today is 26\n");
    }

    return 0;
}