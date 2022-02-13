#include <stdio.h>

int main() 
{
    int nombreEntier;
    printf("Entrez un nombre entier: ");
    scanf("%d", &nombreEntier);
    if (nombreEntier < 0)
    {
        printf("%d est negatif\n", nombreEntier);
    }
    else if (nombreEntier > 0)
    {
        printf("%d est positif\n", nombreEntier);
    }
    else if (nombreEntier == 0)
    {
        printf("%d est zero\n", nombreEntier);
    }
    if (nombreEntier % 2 == 0)
    {
        printf("%d est pair\n", nombreEntier);
    }
    else
    {
        printf("%d est impair\n", nombreEntier);
    }
    return 0;
}