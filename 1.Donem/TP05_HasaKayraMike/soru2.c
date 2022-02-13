#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

//Prototipler
int maxNote(int n[]);
int minNote(int n[]);
int maxOgr(int n[]);
int minOgr(int n[]);
float moyen(int n[]);

int main()
{
    int notlar[N], max[2], min[2];
    float ortalama;
    srand(time(0));
    printf("Ogrencilerin sirasiyla notlari:\n");
    //0 - 100 araliginde N tane rastgele sayi uretir ve bu sayilari sirasiyla ogrencilerin notlari olarak bastirir
    for (int i = 0; i < N; i++)
    {
        notlar[i] = rand() % 101;
        printf("%i. ogrencinin notu: %i\n", i + 1, notlar[i]);
    }
    max[0] = maxNote(notlar);
    max[1] = maxOgr(notlar);
    min[0] = minNote(notlar);
    min[1] = minOgr(notlar);
    ortalama = moyen(notlar);
    printf("\nOrtalama: %.2f\n", ortalama);
    printf("Min     : %i\n", min[0]);
    printf("Max     : %i\n", max[0]);
    printf("\nEn yuksek notu alan ogrenci no: %i\n", max[1]);
    printf("En dusuk notu alan ogrenci no : %i\n", min[1]);
    return 0;
}

/*
Maksimum degeri bulmak icin dizinin ilk elemanini 
maksimum olarak kabul ettim. Sonrasinda diğer değerleri 
sirasiyla karsilastirarak yeni maksimum degeri buldum. 
Ayni yontemi minimum değeri bulmak icin de kullandim
*/

int maxNote(int n[])
{
    int max = n[0];
    for (int i = 0; i < N; i++)
    {
        if (max < n[i])
        {
            max = n[i];
        }
    }
    return max;
}

//En yuksek nota sahip olan ogrencinin numarasını verir
int maxOgr(int n[])
{
    int maxOgr = 1, max = n[0];
    for (int i = 0; i < N; i++)
    {
        if (max < n[i])
        {
            max = n[i];
            maxOgr = i + 1;
        }
    }
    return maxOgr;
}

int minNote(int n[])
{
    int min = n[0];
    for (int i = 0; i < N; i++)
    {
        if (min > n[i])
        {
            min = n[i];
        }
    }
    return min;
}

//En dusuk nota sahip olan ogrencinin numarasını verir
int minOgr(int n[])
{
    int minOgr = 1, min = n[0];
    for (int i = 0; i < N; i++)
    {
        if (min > n[i])
        {
            min = n[i];
            minOgr = i + 1;
        }
    }
    return minOgr;
}

float moyen(int n[])
{
    int toplam = 0;
    for (int i = 0; i < N; i++)
    {
        toplam += n[i];
    }
    return toplam / N;
}

//Min-max durumlari icin dort tane fonksiyon yazmak pek hosuma gitmedi ama baska turlu yapamadim kusura bakmayin :(