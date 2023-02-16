#include <stdio.h>
#include <stdlib.h>

void yildizCiz(char drawWith, int length);
void ucgenCiz(char drawWith, int baseLength);
void tersUcgenCiz(char drawWith, int baseLength);
void piramitCiz(char drawWith, int baseLength);

int main(void)
{
    //yildizCiz('*', 5);
    ucgenCiz('*', 5);
    //tersUcgenCiz('*', 5);
    //piramitCiz('*', 9);
}

void yildizCiz(char drawWith, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", drawWith);
    }
}

void ucgenCiz(char drawWith, int baseLength)
{
    if (baseLength <= 0)
    {
        return;
    }
    ucgenCiz(drawWith, baseLength-1);
    yildizCiz(drawWith, baseLength);
    printf("\n");
    
}

void boslukEkle(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf(" ");
    }
}

void tersUcgenCiz(char drawWith, int baseLength)
{
    for (int i = 1; i <= baseLength; i++)
    {
        boslukEkle(baseLength - i);
        yildizCiz(drawWith, i);
        printf("\n");
    }
}

void piramitCiz(char drawWith, int baseLength)
{
    if (baseLength % 2 == 0)
    {
        baseLength /= 2;
        for (int i = 1; i <= baseLength; i++)
        {
            boslukEkle(baseLength - i);
            yildizCiz(drawWith, i*2);
            printf("\n");
        }
    }
    else
    {
        baseLength = (baseLength - 1) / 2;
        for (int i = 1; i <= baseLength; i++)
        {
            boslukEkle(baseLength - i);
            yildizCiz(drawWith, i+2);
            printf("\n");
        }
    }
    
    
    



}
