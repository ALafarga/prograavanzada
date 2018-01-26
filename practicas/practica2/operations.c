#include <assert.h>
#define MAX_INT 2147483647

int add(int a, int b){
    //me voy al long para ver si me da overflow y 
    //probarlo porque no hay excepciones
    long c = (long) a + b;//c checa los tipos y el ponemos
    // el cast primero para que haga la suma en long
    assert(c < MAX_INT && c > -MAX_INT);
    //if(c < 22147483647 || c > -22147483647)
    //{
    return (int) c;
    //}

    //return a + b;
}

int substraction(int a, int b){
    long c = (long) a - b;//c checa los tipos y el ponemos
    assert(c < MAX_INT && c > -MAX_INT);
        
    return (int) c;

}