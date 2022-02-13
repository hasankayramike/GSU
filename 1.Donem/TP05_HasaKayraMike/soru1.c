#include <stdio.h>
#define N 8

int main()
{
    int notlar[N], max, min, maxOgr = 1, minOgr = 1;
    float toplam = 0;
    
    //a
    for (int i = 0; i < N; i++)
    {
        printf("%i. ogrencinin notu: ", i + 1);
        scanf("%i", &notlar[i]);
        toplam += notlar[i];
    }
    
    printf("Ogrencilerin sirasiyla notlari: ");
    for (int n = 0; n < N; n++)
    {
        printf("%i ", notlar[n]);
    }
    
    //b ve c
    max = notlar[0];
    min = notlar[0];
    for (int k = 0; k < N; k++)
    {
        if (max < notlar[k])
        {
            max = notlar[k];
            maxOgr = k + 1;
        }
        
        else if (min > notlar[k])
        {
            min = notlar[k];
            minOgr = k + 1;
        }
    }
    printf("\nOrtalama: %.2f\n", toplam/N);
    printf("Maksimum: %i\n", max);
    printf("Minimum : %i\n", min);
    
    printf("En yuksek notu alan ogrenci no: %i\n", maxOgr);
    printf("En dusuk notu alan ogrenci no : %i\n", minOgr);
    
    return 0;
}