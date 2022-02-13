#include <stdio.h>

int main()
{
    char input;
    printf("Entrez un caractere en miniscule: ");
    scanf("%c", &input);
    input -= 'a' - 'A';
    printf("En majuscule: %c\n", input);
    return 0;
}