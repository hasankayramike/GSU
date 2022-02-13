#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 99999

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Vous devez entrer 3 arguments");
        return 1;
    }
    int i = 0;
    FILE* text = fopen(argv[1], "r");
    if (!text)
    {
        printf("Pas de fichier!\n");
        exit(1);
    }
    while (!feof(text))
    {
        int c = getc(text);
        if (tolower(c) == tolower(argv[2][0]))
        {
            i++;
        }
    }
    printf("Nombre d'occurance de '%s' dans le fichier %s est: %d\n", argv[2], argv[1], i);
    fclose(text);
    return 0;
}