1111. SQUARES PROBLEM
Time limit: 0.5 second
Memory limit: 64 MB

You are given n (1 ≤ n ≤ 50) squares and point P. The distance between P and square is the shortest line segment that connects P with the contour or the internal area of the square. If P is inside the square then the distance is zero. It is possible some squares to be points i.e. to have vertices that coincide. Write a program that will sort the squares in ascending order according the distance from P.

Input
The first line contains the integer n. The following n lines contain four integers in the range (−9999, 9999). The first two numbers define the x and y coordinates of one of the vertices of the square, the next two numbers define the opposite vertex. The last line contains the x and y coordinates of P.

Output
The output should be a line containing the ids of the squares sorted according to the distance from P. The ids are defined according to the order in which the squares are given in the input. Use ids to break ties i.e. if two squares are the same distance from P then write the square with the lowest id first. Using 10^−14 precision when comparing the distances is accurate enough.

Sample
input	    output
2           1 2
0 0 1 1
0 3 1 4
0 0

Obtener el cuadrado dependiendo del par de puntos que te dieron.
    los puntos seran ordenados como (x, y) los primeros dos, seguidos de (xinv, yinv) que nos da el vertice opuesto con lo que podemos completar el cuadrado. Se guardaran en las variables cuadradoX0 y cuadradoY0 con los inversos cuadradoXinv0 y cuadradoYinv0 y calcularemos los otros dos vertices del cuadrado que seran cuadradoX1 y cuadradoY1 con los inversos cuadradoXinv1 y cuadradoYinv1 con lo que tenemos los cuatro puntos: 
        cuadradoX0, cuadradoY0
        cuadradoXinv0, cuadradoYinv0
        cuadradoX1, cuadradoY1  
        cuadradoXinv1, cuadradoYinv1

Calcular la distancia del punto al cuadrado: por medio de encontrar el punto mas cercano del cuadrado con respecto al punto de referencia

Punto mas cercano del cuadrado a la referencia: 9 casos (nota: lo llamaremos punto mas cercano pero podriamos llamarlo igualmente el cuadrado.)
    1) El punto se encuentra dentro del cuadrado. En este caso la distancia es 0
    2) El punto se encuentra en el mismo eje de las X pero arriba (Y mayor) que la referencia 
    3) El punto se encuentra en el mismo eje de las Y pero a la derecha (X mayor) que la referencia 
    4) El punto se encuentra en el mismo eje de las X pero abajo (Y menor) que la referencia 
    5) El punto se encuentra en el mismo eje de las x pero arriba (Y mayor) que la referencia 
    6) El punto se encuentra a la derecha y arriba de la referencia por lo que el punto sera la X y Y menores del cuadrado.
    7) El punto se encuentra a la derecha y abajo de la referencia por lo que el punto sera la X menor y Y mayor del cuadrado.
    8) El punto se encuentra a la izquierda y abajo de la referencia por lo que el punto sera la X y Y mayores del cuadrado.
    9) El punto se encuentra a la izquierda y arriba de la referencia por lo que el punto sera la X mayor y Y menor del cuadrado.

PONERLE CUANDO SE USA!!
Para calcular la distancia entre puntos que en los casos 2), 3), 4), 5) es simplemente el delta, en el caso 1) es 0 y en los demas se usa la formula
    sqrt((pow((x2-x1),2))+(pow((y2-y1),2)))

Calcular la de cada cuadrado que hayan metido en una estructura que guarde el orden en que entro y la distancia en si para poder ordenarlos
    atributos de la estructura 
        ID              integer
        distancia       double     

            Debido a que nos piden una precision de 10^-14 se necesitan hacer operaciones con double para poder llegar a esa precision

ordenar los resultados de distancia menor a mayor por medio del algoritmo de acomodamiento QuickSort
Regresar resultado que sera los IDs de los elementos del arreglo 

Casos excepcionales,
input incorrecto

Notas:
Trate de crear los arreglos dinamicos en relacion a "n" pero me dio error de compilacion asi que los puse eventualmente al maximo que es 50 con posibilidad de mejora

No he podido lograr los inputs
https://courses.cs.washington.edu/courses/cse351/14sp/sections/1/Cheatsheet-c.pdf
guiando en esta pagina probra sscanf

Mejoras:
Debo de revisar que es realmente lo que se necesita guardar pues en estos momentos guardo todo

TODO:
-desarrollar quick sort
-revisar si necesito completar todos los cuadrados
-calcular la distancia en los 9 casos

Falle a la hora de usar el metodo de programacion TDD donde se hacen testeos, debo revisar el c.scaffold