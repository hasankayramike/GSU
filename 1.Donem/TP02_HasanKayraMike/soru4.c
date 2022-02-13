#include <stdio.h>

int main()
{
    int input;
    int output = 0;
    int somme = 0;
    printf("Entrez un entier positif: ");
    scanf("%d", &input);
    while (output <= input)
    {
        printf("%d ", output);
        somme += output; 
        output += 1;
    }
    printf("\nLa somme est %d", somme);
    return 0;
}
