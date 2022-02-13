#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if ((argv[2] == NULL) || (argv[1] == NULL))
    {
        printf("Eksik arguman girdiniz\n");
        return 1;
    }
    else if (atoi(argv[1]) == 0)
    {
        for (int i = 0, n = atoi(argv[2]); i < n; i++)
        {
            printf("%s ", argv[1]);
        }
        printf("\n");
        return 0;
    }
    
    else
    {
        printf("Once karakter dizisini giriniz!\n");
        return 1;
    }
}