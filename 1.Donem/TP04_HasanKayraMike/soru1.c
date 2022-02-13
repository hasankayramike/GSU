#include <stdio.h>

int main()
{
    int toplamFor = 0 , toplamWhile = 0 , toplamDoWhile = 0, i = 1, n = 100; 
    
    //For kullanarak aynı ciktiyi veren komut
    for (int i = 1; i <= n; i++)
    {
        toplamFor += i;
    }
    printf("For dongusu icin sonuc: %i\n", toplamFor);
    
    //While kullanarak aynı ciktiyi veren komut
    i = 1;
    while(i <= n)
    {
        toplamWhile += i;
        i++;
    }
    printf("While dongusu icin sonuc: %i\n", toplamWhile);
    
    //Do-while kullanarak aynı ciktiyi veren komut
    i = 1;
    do
    {
        toplamDoWhile += i;
        i++;
    } 
    while (i <= n);
    printf("Do-While dongusu icin sonuc: %i\n", toplamDoWhile);
    return 0;
}

