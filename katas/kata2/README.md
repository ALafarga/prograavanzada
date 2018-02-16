Kata2

A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

Primero guardaria el password en una arreglo de caracteres y usaria su codigo ascii para saber si son numeros o letras, si son mayusculas minusculas o simbolos.
Despues revisaria se hay alguna que se repita mas de dos veces seguidas. 
Con el tamano del arreglo sabre de que tamano es el password.
Por cada una de las condiciones que no se satisfasgan sumare uno a la variable que la funcion regresara.
