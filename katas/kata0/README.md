KATA0

Given an array of integers, return indices of the two numbers such that they add up to a specific target. You may assume that each input would have exactly one solution, and you may not use the same element twice.

Usare un algoritmo de busqueda para poder resolver el problema. El mas viable es el de HashTable por ser de complejidad constante.
Entonces empezamos por meter el arreglo a la tabla Hash.
Agarramos el primer numero y buscamos su complementario que nos dara la suma que estamos buscando. Seguimos con el siguiente numero y asi sucesivamente.
Regresamos esos dos numeros que satisfacen la ecuacion y terminamos.