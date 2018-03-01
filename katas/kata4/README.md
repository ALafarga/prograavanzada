
Valid Number

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.


Suposiciones

La entrada del numero esta limitada a 255 caracteres
No se aceptan dos tokens numericos
Los espacios en blanco se ignoran
    Lo que implica que cuando se encuentre un espacio en blanco despues del numero por ejemplo un
    18 08 sera invalido
Los numeros pueden tener signo
Los numeros decimales con validos
    Donde el punto los delimita
    La coma se puede usar para representar numeros de millares
        No es valido usar la coma como punto decimal
        Las comas deben estar separadas siempre por 3 caracteres de otra forma sera un numero invalido
    Si el numero es menor a 1 solo puede tener un 0 antes del punto 
        Acepta tambien sin el 0 antes del punto
Los numeros exponenciales son validos con todo y signo
    la exponencial debe ser una "e" minuscula
    Despues de la e no puede haber punto decimal ni coma
    

Solucion

Regresa true si es numero valido, false si no lo es 
Revisamos el tamano del string que se revisa, si es mayor a 255 regresamos false sino contunuamos
    Leemos el primer caracter del string
    Si es un espacio seguimos hasta encontrar un caracter diferente a espacio
        Se convierte el character a int con la funcion int atoi( const char* str)
            Se checa si el caracter es un digito con la funcion int isdigit (int c)
                Si no regresa false
        Si no es int se prueba si es ., e, ',', +, -
            si es .
                se lee los siguentes caracteres hasta llegar a espacio,
                    si es espacio 
                        revisamos que lo demas del string que queda siga siendo espacio
                            sino regresa false
                        regresa true
                    si es digito
                        revisa siguiente caracter, todos deben ser digitos regresa true
                            sino regresa false
                    si es ,
                        regresa false                
            si es e
                se lee los siguentes caracteres hasta llegar a espacio,
                    si es espacio 
                        revisamos que lo demas del string que queda siga siendo espacio
                            sino regresa false
                        regresa true
                    si es digito
                        revisa siguiente caracter, todos deben ser digitos regresa true
                            sino regresa false
                    si es ,
                        regresa false
                    si es +    
                            se lee los siguentes caracteres hasta llegar a espacio,
                        si es espacio 
                            revisamos que lo demas del string que queda siga siendo espacio
                                sino regresa false
                            regresa true
                        si es digito
                            revisa siguiente caracter, todos deben ser digitos regresa true
                                sino regresa false
                    si es -
                            se lee los siguentes caracteres hasta llegar a espacio,
                        si es espacio 
                            revisamos que lo demas del string que queda siga siendo espacio
                                sino regresa false
                            regresa true
                        si es digito
                            revisa siguiente caracter, todos deben ser digitos regresa true
                                sino regresa false
            si es ,
                 se lee los siguentes tres caracteres. Los tres deben ser digitos
                    se revisa que haya ',', . o espacio
                      si es espacio 
                        revisamos que lo demas del string que queda siga siendo espacio
                            sino regresa false
                        regresa true
                    sino regresa false
                 sino regresa false
            si es +
                se lee los siguentes caracteres hasta llegar a espacio,
                    si es espacio 
                        revisamos que lo demas del string que queda siga siendo espacio
                            sino regresa false
                        regresa true
                    si es digito
                        revisa siguiente caracter, todos deben ser digitos regresa true
                            sino regresa false
                regresa false  
            si es -
                se lee los siguentes caracteres hasta llegar a espacio,
                    si es espacio 
                        revisamos que lo demas del string que queda siga siendo espacio
                            sino regresa false
                        regresa true
                    si es digito
                        revisa siguiente caracter, todos deben ser digitos regresa true
                            sino regresa false
                regresa false
        De lo contrario se regresa false
Si no regresa false