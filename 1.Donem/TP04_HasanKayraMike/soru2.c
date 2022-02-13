#include <stdio.h>

//Prototipler
int fahrenheit(int c);
int celcius(int f);

int main()
{
    //cF: Celcius'u Fahrenheit'a donusturur, fC: Fahrenheit'i Celcius'a donusturur  
    int c, f, cF, fC;
    
    //Birinci tabloyu yazdirir
    printf("Celcius -----> Fahrenheit:\n");
    printf("    C               F\n");
    printf("--------------------------\n");
    for (c = 0; c < 101; c += 10)
    {
        cF = fahrenheit(c);
        printf("    %i              %i\n", c, cF);
    }
    printf("\n");
    //Ikinci tabloyu yazdirir
    printf("Fahrenheit -----> Celcius:\n");
    printf("    F               C\n");
    printf("--------------------------\n");
    for (f = 32; f < 213; f += 20)
    {
        fC = celcius(f);
        printf("    %i              %i\n", f, fC);
    }
    return 0;
}

//Fonksiyonlar
int fahrenheit(int c)
{
    int f = c * 18 / 10 + 32;
    return f;
}

int celcius(int f)
{
    int c = (f - 32) / 1.8;
    return c;
}