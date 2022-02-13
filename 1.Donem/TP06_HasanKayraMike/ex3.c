#include <stdio.h>

/*
swap1 fonksiyonu değişkenleri direkt olarak parametre alır ve 
o değişkenler üzerinde fonksiyonun sınırları içerisinde işlemler yapar.
Fonksiyon işini tamamladıktan sonra a ve b değişkenleri main fonksiyonunda 
ilk tanımlandıkları değerler ile devam eder.
swap2 fonksiyonu parametre olarak değişkenlerin adreslerini alıp o adreslere 
giderek işlemlerini yaptığından değişkenler üzerinde yapılan değişiklikler kalıcı olur.
*/

void swap1(int a, int b);
void swap2(int *a, int *b);

int main()
{
    int a, b;
    printf("Entrez 2 entiers a et b: ");
    scanf("%i%i", &a, &b);
    printf("Avant swap : a = %i, b = %i\n", a, b);
    swap1(a, b);
    printf("Apres swap1: a = %i, b = %i\n", a, b);
    swap2(&a, &b);
    printf("Apres swap2: a = %i, b = %i\n", a, b);
    return 0;
}

void swap1(int a, int b)
{
    int tmp = b;
    b = a;
    a = tmp;
}

void swap2(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}