#include <stdio.h>

int charCounter(char *c);

int main()
{
    int length;
    char input[99999]; 
    printf("Entrez une chaine de caractere: ");
    gets(input);
    length = charCounter(input);
    printf(">> La longueur de la chaine '%s' est %i\n", input, length);
    return 0;
}

int charCounter(char *c)
{
    int i;
    for (i = 0; c[i] != '\0'; i++);
    return i;
}