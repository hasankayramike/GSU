#include <stdio.h>

int main()
{
    int baseImposable;
    printf("Entrez la base imposable: ");
    scanf("%d", &baseImposable);
    if (baseImposable > 0 && baseImposable <= 24000)
    {
        printf("Taux d'imposition: %15\n");
    }
    else if (baseImposable > 24000 && baseImposable <= 53000)
    {
        printf("Taux d'imposition: %20\n");
    }
    else if (baseImposable > 53000 && baseImposable <= 130000)
    {
        printf("Taux d'imposition: %27\n");
    }
    else if (baseImposable > 130000 && baseImposable <= 650000)
    {
        printf("Taux d'imposition: %35\n");
    }
    else if (baseImposable > 650000)
    {
        printf("Taux d'imposition: %40\n");
    }
    return 0;
}