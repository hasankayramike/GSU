#include <stdio.h>

int main()
{
    int input;
    int output = 0;
    printf("Entrez un entier: ");
    scanf("%d", &input);
    output = input;
    while (output >= 0)
    {        
        printf("%d ", output); 
        output -= 1;
    }
    output = 0;
    printf("\n");
    while (output <= input)
    {
        printf("%d ", output); 
        output += 1;
    }
    return 0;
}
