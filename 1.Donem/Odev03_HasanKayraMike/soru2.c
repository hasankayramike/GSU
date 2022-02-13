#include <stdio.h>
#define N 10

int chercheMax(int *tab, int size);

int main()
{
    int a[N] = {34, 78, 56, 0, 12, 89, 67, 45, 90, 23};
    int index = chercheMax(a, N);
    printf("L'indice de max est %i\n", index);
    printf("La valeur de max est %i\n", *(a + index));
    return 0;
}

int chercheMax(int *tab, int size)
{
    int *max = tab, index;
    for (int *i = tab; i < tab + size; i++)
    {
        if (*i > *max)
        {
            max = i;
        }  
    }
    index = max - tab;
    return index;
}