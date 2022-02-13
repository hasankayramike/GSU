#include <stdio.h>

char enMiniscule(char c);

int main()
{
    char input, inputMin;
    printf("Entrez un caractere: ");
    scanf("%c", &input);
    inputMin = enMiniscule(input);
    printf("En miniscule       : %c\n", inputMin);
    return 0;
}

char enMiniscule(char c)
{
    char output;
    if (c >= 'a' && c <= 'z')
    {
        output = c;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        output = c + 'a' - 'A';
    }
    else
    {
        output = '?';
    }
    return output;
}