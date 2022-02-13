#include <stdio.h>
#include <stdlib.h>
#define N 99999

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Vous devez entrer 2 arguments");
        return 1;
    }
    char isim[N];
    int i = 0, not; 
    float toplam = 0;
    FILE *notlar = fopen(argv[1], "r");
    if (!notlar)
    {
        printf("Pas de fichier!\n");
        exit(1);
    }
    while (!feof(notlar))
    {
        fscanf(notlar, "%s%d\n", isim, &not);
        toplam += not;
        i++;
    }
    printf("Ortalama: %.2f\n", toplam / i);
    return 0;
}