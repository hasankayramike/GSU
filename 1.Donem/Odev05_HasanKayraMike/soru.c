#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 99999

void caseChanger(char *src, char *dest, char *opr);

int main(int argc, char *argv[])
{
    char output[N];
    if (argc < 3)
    {
        printf("Eksik arguman girdiniz!\n");
        return 1;
    }
    else
    {
        if (argc > 3)
        {
            printf("Fazla arguman girdiniz ama olsun, hizmet icin buradayiz...\n");
        }
        if (strcmp(argv[1], "-d") == 0)
        {
            printf("Girdiginiz karakter dizisi: %s\n", argv[2]);
        }
        else if (strcmp(argv[1], "-u") == 0)
        {
            caseChanger(argv[2], output, "upper");
        }   
        else if (strcmp(argv[1], "-l") == 0)
        {
            caseChanger(argv[2], output, "lower");
        }
        else if (strcmp(argv[1], "-s") == 0)
        {
            caseChanger(argv[2], output, "sentence");
        }
        else
        {
            printf("Oyle bir opsiyon yok! Bay bay!\n");
            return 1;
        }
        return 0;
    }
}

void caseChanger(char *src, char *dest, char *opr)
{
    for (int i = 0, n = strlen(src); i < n; i++)
    {
        if (strcmp(opr, "upper") == 0)
        {
            dest[i] = toupper(src[i]);
        }
        else if (strcmp(opr, "lower") == 0)
        {
            dest[i] = tolower(src[i]);
        }
        else if (strcmp(opr, "sentence") == 0)
        {
            if (i == 0)
            {
                dest[i] = toupper(src[i]);
            }
            else
            {
                dest[i] = tolower(src[i]);
            }
        }
    }
    printf("%s\n", dest);
}