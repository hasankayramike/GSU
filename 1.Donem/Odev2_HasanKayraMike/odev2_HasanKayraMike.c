#include <stdio.h>

//a sikkindaki fonksiyon
int sommeChiffres(int n)
{
    int sumOnesDigits = 0;
    int onesDigit = n % 10;
    int otherDigits = n / 10;
    while (otherDigits >= 10)
    {
        sumOnesDigits += otherDigits % 10;
        otherDigits = otherDigits / 10;
    }
    return onesDigit + otherDigits + sumOnesDigits;
}

//b sikkindaki fonksiyon
int harshad(int n)
{
    int divisor = sommeChiffres(n);
    if (n % divisor == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//c sikkindaki fonksiyon
void afficheHarshad(int x)
{
    int counter = 1;
    int n = 1;
    while (counter <= x)
    {
        int isHarshad = harshad(n);
        if (isHarshad)
        {
            printf("%d ", n);
            if (counter % 10 == 0)
            {
                printf("\n");
            }
            counter += 1;
        }
        n += 1;
    }
}

//d sikki icin olan main fonksiyonu
int main()
{
    int x;
    printf("Entrez un entier positif: ");
    scanf("%d", &x);
    afficheHarshad(x);
    return 0;
}