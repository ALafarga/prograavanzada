int matchPeliculas(int tVuelo, int *listaPelis)
{
    //hash con todas las peliculas donde el key es la longitud de la misma
    hash hashPelis; 
    //hash movies into hashPelis
    for (int i = 0; i < listaPelis.length; i++)
    {
        int match = hashPelis.hashGet(tVuelo - listaPelis[i]);
        if (match != 0)
        {
            return 1;
        }
    }
    return 0;
}