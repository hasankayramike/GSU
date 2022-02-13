#include <stdio.h>

int main()
{
    for (int i = 0; i < 256; i++)
    {
        printf("%i - %c      ", i, i);
        if (i != 0 && i % 10 == 0)
        {
            printf("\n");
        }
    }
    return 0;
}