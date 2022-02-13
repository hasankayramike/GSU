#include <stdio.h>
int main()
{
    int input;
    int output = 1;
    int multiplier = 1;
    printf("Entrez un entier positif: ");
    scanf("%d", &input);
    while (output <= input)
    {        
        while (multiplier <= output)
        {
            printf("%d ", output);
            multiplier += 1;
        }
        multiplier = 1;
        printf("\n");
        output += 1;
    }
    return 0;
}