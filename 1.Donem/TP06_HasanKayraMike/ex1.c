#include <stdio.h>

/*

la valeur de a = 10
&a est l’adresse de a = 0x61FE1C
&b est l’adresse de b = 0x61FE18
&x est l’adresse de x = 0x61FE10
x pointe sur l’addresse de a = 0x61FE1C
*x contient la valeur de a = 10
la taille de x = 8
la taille de *x = 4

*/

int main()
{
    int a = 10, b;
    int *x = &a;
    printf("La valeur de a = %i\n", a);
    printf("&a est l'adresse de a = 0x%x\n", &a);
    printf("&b est l'adresse de b = 0x%x\n", &b);
    printf("&x est l'adresse de x = 0x%x\n", &x);
    printf("x pointe sur l'adresse de a = 0x%x\n", x);
    printf("*x contient la valeur de a = %i\n", *x);
    printf("La taille de x = %i\n", sizeof(x));
    printf("La taille de *x = %i\n", sizeof(*x));
    return 0;
}