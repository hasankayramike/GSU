#include <stdio.h>

//Prototipler
int faktoriyel(int n);
int solFaktoriyel(int n);

int main()
{
    int fSonuc, sfSonuc;
    
    printf("  Faktoriyel\n");
    printf("------------------\n");
    for (int i = 0; i < 11; i++)
    {
        fSonuc = faktoriyel(i);
        printf("%i! = %i\n", i, fSonuc);
    }
    
    printf("\n");
    
    printf("  Sol Faktoriyel\n");
    printf("---------------------\n");
    for (int i = 0; i < 11; i++)
    {
        sfSonuc = solFaktoriyel(i);
        printf("!%i = %i\n", i, sfSonuc);
    }
    return 0;
}

int faktoriyel(int n)
{
    int sonuc = 1;
    for (int i = 1; i < n + 1; i++)
    {
        sonuc *= i;
    }
    return sonuc;
}

int solFaktoriyel(int n)
{
    int k, sonuc = 0;
    for (int i = 0; i < n; i++)
    {
        k = faktoriyel(i);
        sonuc += k;
    }
    return sonuc;
}