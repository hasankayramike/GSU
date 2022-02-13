#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int output;
    if (argv[2] == NULL)
    {
        printf("En az bir sayi daha girmeniz lazim!\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = argc; i < n; i++)
        {
            output += atoi(argv[i]);
        }
    }
    printf("Toplam: %i\n", output);
    return 0;
}