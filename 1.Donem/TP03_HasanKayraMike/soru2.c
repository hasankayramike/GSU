#include <stdio.h>

int myPower(int a, int b)
{
    int exponent = 0;
    int result = 1;
    while (exponent < b)
    {
        result *= a;
        exponent += 1;
    }
    return result;
}

int main()
{
    int x, y, finalResult;
    printf("Entrez la base et l'exposant: ");
    scanf("%d%d", &x, &y);
    finalResult = myPower(x, y);
    printf("Resultat: %d\n", finalResult);
    return 0;
}