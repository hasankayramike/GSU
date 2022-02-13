#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 99999

void toUpper(char src[], char dest[]);
char findMax(char *s);
char findMin(char *s);
void crypto(char src[], char dest[], int key);
void ayrac(char *s);

int main()
{
    char input[N], upperCase[N], encrypted[N], max, min;
    int key;
//1)
    printf("Sifrelenecek karakter dizisini girin: ");
    gets(input);
    ayrac(input);
    printf("Sifrelenecek karakter dizisi: %s\n", input);
//2)
    printf("Buyuk harfe cevrilmis dizi  : ");
    toUpper(input, upperCase);
//3)
    ayrac(input);
    max = findMax(upperCase);
    min = findMin(upperCase);
    printf("Max degerli karakter: %c (%i)\n", max, (int) max);
    printf("Min degerli karakter: %c (%i)\n", min, (int) min);
//4)
    key = max - min;
    printf("Sifre anahtari      : %i\n", key);
//5)
    printf("Sifrelenmis dizi    : ");
    crypto(upperCase, encrypted, key);
    ayrac(input);
    return 0;
}

//2. sorudaki fonksiyon
void toUpper(char src[], char dest[])
{
    for (int i = 0, n = strlen(src); i < n; i++)
    {
        dest[i] = toupper(src[i]);
        printf("%c", dest[i]);
    }
    printf("\n");
}

//3. sorudaki ilk fonksiyon
char findMax(char *s)
{
    char max = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (s[i] > max)
            {
                max = s[i];
            }
        }
    }
    return max;
}

//3. sorudaki ikinci fonksiyon
char findMin(char *s)
{
    char min = 127;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (s[i] < min)
            {
                min = s[i];
            }
        }
    }
    return min;
}

//5. sorudaki fonksiyon
void crypto(char src[], char dest[], int key)
{
    for (int i = 0, n = strlen(src); i < n; i++)
    {
        if (isalnum(src[i]))
        {
            dest[i] = src[i] + key; 
        }
        else
        {
            dest[i] = src[i];
        }
        
        printf("%c", dest[i]);
    }
    printf("\n");
}

//Kod daha guzel gozuksun diye ayrac ekleyen bir fonksiyon yazdim
void ayrac(char *s)
{
    for (int i = 0, n = strlen(s); i < n + 39; i++) printf("-");
    printf("\n");
}