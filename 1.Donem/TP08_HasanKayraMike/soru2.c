#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a[25];
    printf("Before:\n");
    for (int i = 0; i < 25; i++)
    {
        a[i] = rand();
        printf("%i ", a[i]);
    }
    printf("\nAfter;\n");
    for (int n = 0; n < 25; n++)
    {
        printf("%i ", a[n] + atoi(argv[1]));
    }
    return 0;
}