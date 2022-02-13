#include <stdio.h>
#define N 10

//size adet elemanı olan x listesinin en küçük elemanının adresini döndüren fonksiyon.
int* minAdr(int x[], int size);

int main()
{
    int a[N] = {34, 78, 56, 0, 12, 89, 67, 45, 90, 23};
    int *min = minAdr(a, N);
    printf("Le plus petit nombre dans le tableau: %i\n", *min);
    printf("L'adresse du plus petit nombre      : 0x%x\n", min);
    printf("L'indice du plus petit nombre       : %i\n", (min - a));
    return 0;
}

int* minAdr(int x[], int size)
{
    int *min = x;
    for (int *i = x; i < x + size; i++)  
    {
        if (*i < *min)
        {
            min = i;
        }
    }
    return min;
}