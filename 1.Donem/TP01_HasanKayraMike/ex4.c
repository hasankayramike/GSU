#include <stdio.h>

int main()
{
    int gunSayisi;
    printf("Gun sayisini giriniz: ");
    scanf("%d", &gunSayisi);
    int gecenYil = (gunSayisi / 365);
    int gecenHafta = ((gunSayisi % 365) / 7);
    int gecenGun = (((gunSayisi % 365) % 7));
    printf("Yil   : %d\n", gecenYil);
    printf("Hafta : %d\n", gecenHafta);
    printf("Gun   : %d\n", gecenGun);
    if (gunSayisi < 1825)
    {
        printf("Karar : Saklamaya devam...\n");
    }
    else
    {
        printf("Karar : IMHAAAAA!!!!\n");
    }
    return(0);
}