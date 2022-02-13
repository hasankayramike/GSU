#include <stdio.h>
#define N 10

int main()
{
    int a[N] = {34, 78, 56, 0, 12, 89, 67, 45, 90, 23};
    int *p;
    p = a; //a = &a[0] ==> p = &a[0]
//a) &p
    //p pointer'ı a listesinin ilk elemanının adresini tutar. &p ise p pointer'ının adresini belirtir. &p != p.
    printf("\na)\n&p = 0x%x\n", &p);
    printf("p  = 0x%x\n", p);
//b) *p + 5
    //*p, p'nin tuttugu adreste bulunan degeri verir. *p + 5 ise o adreste bulunan degerin 5 fazlasini.
    //p = &a[0] oldugundan *p = a[0]. *p + 5 = 39.
    printf("\nb)\n*p + 5 = %i\n", *p + 5);
    printf("a[0] + 5 = %i\n", a[0] + 5);
//c) *(p + 3)
    /* p bir integer'in adresini tuttugu icin kendisine 1 eklenirse 4 byte sonraki adresi gosterir. 
       Integer degisken tutan bir listeyle ilgilendigimiz icin listenin elemanlari dorder byte ardisik siralanir.
       p = &a[0] oldugu icin p + x = &a[x] olur. Ifadenin basindaki * isareti ise o adresteki degeri dondurur. Yani
       *(p + 3) = *(&a[3]) = a[3] */
    printf("\nc)\n*(p + 3) = %i\n", *(p + 3));
    printf("a[3] = %i\n", a[3]);  
//d) &a[4] - 1
    /* Ayni mantiktan hareketle, int olarak tanimli listenin bir elemaninin adresinden 1 cikarirsak 4 byte onceki adrese,
       yani bir onceki elemanin adresine ulasirirz. &a[4] - 1 = &a[3] */
    printf("\nd)\n&a[4] - 1 = 0x%x\n", &a[4] - 1);
    printf("&a[3] = 0x%x\n", &a[3]);
//e) a + 2
    /* a = &a[0]. Onceki siklardaki mantik burada da gecerli. &a[0] + 2 = &a[2] olur cünkü listedeki elemanlar hafizada
       ardisik dizilir. Adrese 2 eklemek, 2 sonraki elemana gitmek demektir. */
    printf("\ne)\n&a[0] = 0x%x\n", &a[0]);
    printf("a = 0x%x\n", a);
    printf("a + 2 = 0x%x\n", a + 2);
    printf("&a[2] = 0x%x\n", &a[2]);
//f) &a[6] - p
    /* Az onceki ornekten yola cikalim &a[0] + 2 = &a[2] olarak bulmustuk. &a[0]'i esitligin diger tarafina alirsak
       &a[2] - &a[0] = 2 olur, bu da liste elemanlarının adreslerinin ardısik tutulmasiyla aciklanir. p = a = &a[0]
       ise &a[6] - p = &a[6] - &a[0] = 6 olur. */
    printf("\nf)\n&a[6] - p = %i\n", &a[6] - p);
//g) p + (*p - 10)
    /* Burada islem onceligine gore hareket etmeliyiz. * ifadesi parantezin icinde kaldiğindan p - 10'un degil p'nin
       belirttigi adresteki degeri gosterir. *p = *(&a[0]) = a[0] = 34, *p - 10 = 24. Simdi ise p + 24 islemini yapacagiz.
       p = &a[0] oldugu icin p + 24, a[0]'in adresinden 24 tane 4 byte sonra gelen adrestir. */
    printf("\ng)\n*p - 10 = %i\n", *p - 10);
    printf("p + (*p - 10) = 0x%x\n", p + (*p - 10));
    printf("&a[24] = 0x%x\n", &a[24]);
//h) *(p + *(p + 8) - a[7])
    /* *(p + 8) = *(&a[0] + 8) = *(&a[8]) = a[8] 
       *(p + a[8] - a[7]) = *(&a[0] + 90 - 45) = *(&a[0] + 45) = *(&a[45]) = a[45]
       a listesi 10 elemanli oldugu icin a[45] rastgele bir deger olur. */
    printf("\nh)\n*(p + *(p + 8) - a[7]) = %i\n", *(p + *(p + 8) - a[7]));
    printf("a[45] = %i\n", a[45]);
//i) p + 11
    // p = &a[0] oldugu icin p + 11, a[0]'in adresinden 11 tane 4 byte sonra gelen adrestir.
    printf("\ni)\np + 11 = 0x%x\n", p + 11);
    printf("&a[11] = 0x%x\n", &a[11]);
//j) *(p + 11)
    // (p + 11)'in &a[11] oldugunu gostermistik. Bu nedenle *(p + 11) = *(&a[11]) = a[11] olur. a listesi 10 elemanli oldugu icin a[11] rastgele bir deger olur.
    printf("\nj)\n*(p + 11) = %i\n", *(p + 11));
    printf("a[11] = %i\n", a[11]);
}
