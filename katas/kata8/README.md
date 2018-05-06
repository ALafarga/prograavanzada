Kata 8
-Problem

You've built an inflight entertainment system with on-demand movie streaming.

Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.

Write a function that takes an integer flight_length (in minutes) and a list of integers movie_lengths (in minutes) and returns a boolean indicating whether there are two numbers in movie_lengths whose sum equals flight_length.

When building your function:

Assume your users will watch exactly two movies
Don't make your users watch the same movie twice
Optimize for runtime over memory

Para resolver esto me parece conveniente utiliza una hash table que use como key el length de la pelicula.

Entonces una vez que se le hizo hash a la lista de peliculas recorremos la lista y buscamos un hashget que nos regrese la pelicula que no sea mayor que el tiempo del vuelo - el tiempo de la pelicula "i" de la lista y regresa uno si es diferente de nulo