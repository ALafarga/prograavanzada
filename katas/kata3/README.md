Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L(Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:

Input: "UD" Output: true

Example 2:

Input: "LL" Output: false

Usando dos variables enteras ejeX y ejeY.
Obtengo cada caracter del string y cuento cuantas veces aparece la U y por cada una aumento en 1 el ejeY, por cada vez que aparezca la D decremento en un el ejeY.
De igual manera cada que aparece una R aumento en uno el ejeX y cada que aparece una L decremento en uno el ejeX.
Si al final del movimiento del robot ejeX y ejeY son igual a 0 entonces regreso a su punto original de cualquier otra forma no lo hizo.